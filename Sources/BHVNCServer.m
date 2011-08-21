//
//  BHVNCServer.m
//  Exposed
//
//  Created by Brandon Holland on 10-10-10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "BHVNCServer.h"
#import "IOSurface.h"

#pragma mark -
#pragma mark C Functions
#pragma mark

static void clientGone(rfbClientPtr cl)
{
	NSAutoreleasePool *localPool = [[NSAutoreleasePool alloc] init];
	
	NSString *clientAddress = [NSString stringWithCString: cl->host encoding: NSUTF8StringEncoding];
	NSLog(@"Exposed -> client gone: %@", clientAddress);
	[[NSNotificationCenter defaultCenter] postNotificationName: kBHVNCServerClientDisconnectedNotification object: clientAddress];
	
	[localPool drain];
}

static enum rfbNewClientAction newClient(rfbClientPtr cl)
{	
	NSAutoreleasePool *localPool = [[NSAutoreleasePool alloc] init];
	
	NSString *clientAddress = [NSString stringWithCString: cl->host encoding: NSUTF8StringEncoding];
	NSLog(@"Exposed -> new client: %@", clientAddress);
	[[NSNotificationCenter defaultCenter] postNotificationName: kBHVNCServerClientConnectedNotification object: clientAddress];
	
	cl->clientData = (void *)1;
	cl->clientGoneHook = clientGone;
	
	[localPool drain];
	return RFB_CLIENT_ACCEPT;
}

static rfbBool passCheck(rfbClientPtr client, const char *data, int size) 
{
	NSAutoreleasePool *localPool = [[NSAutoreleasePool alloc] init];
	
	NSString *passwordString = (NSString *)client->screen->authPasswdData;
	char *password = (char *)[passwordString cStringUsingEncoding: NSUTF8StringEncoding];
	rfbEncryptBytes(client->authChallenge, password);
	BOOL returnValue = !memcmp(client->authChallenge, data, size);
	
	[localPool drain];
	return returnValue;
}

static void kbdEvent(rfbBool down, rfbKeySym keySym, struct _rfbClientRec *cl)
{
	NSAutoreleasePool *localPool = [[NSAutoreleasePool alloc] init];
	if(down)
	{
		switch(keySym)
		{
			case XK_Up:
			{
				BREvent *event = [BREvent eventWithAction: kBREventRemoteActionUp value: 1];
				[[BRApplication sharedApplication] dispatchEventOnEventThread: event];
				
				event = [BREvent eventWithAction: kBREventRemoteActionUp value: 0];
				[[BRApplication sharedApplication] dispatchEventOnEventThread: event];
				break;
			}
			case XK_Down:
			{
				BREvent *event = [BREvent eventWithAction: kBREventRemoteActionDown value: 1];
				[[BRApplication sharedApplication] dispatchEventOnEventThread: event];
				
				event = [BREvent eventWithAction: kBREventRemoteActionDown value: 0];
				[[BRApplication sharedApplication] dispatchEventOnEventThread: event];
				break;
			}
			case XK_Left:
			{
				BREvent *event = [BREvent eventWithAction: kBREventRemoteActionLeft value: 1];
				[[BRApplication sharedApplication] dispatchEventOnEventThread: event];
				
				event = [BREvent eventWithAction: kBREventRemoteActionLeft value: 0];
				[[BRApplication sharedApplication] dispatchEventOnEventThread: event];
				break;
			}
			case XK_Right:
			{
				BREvent *event = [BREvent eventWithAction: kBREventRemoteActionRight value: 1];
				[[BRApplication sharedApplication] dispatchEventOnEventThread: event];
				
				event = [BREvent eventWithAction: kBREventRemoteActionRight value: 0];
				[[BRApplication sharedApplication] dispatchEventOnEventThread: event];
				break;
			}
			case XK_Escape:
			{
				BREvent *event = [BREvent eventWithAction: kBREventRemoteActionMenu value: 1];
				[[BRApplication sharedApplication] dispatchEventOnEventThread: event];
				break;
			}
			case XK_Return:
			case XK_KP_Enter:
			{
				BREvent *event = [BREvent eventWithAction: kBREventRemoteActionPlay value: 1];
				[[BRApplication sharedApplication] dispatchEventOnEventThread: event];
				break;
			}
			case XK_F1:
			{
				BREvent *event = [BREvent eventWithAction: kBREventRemoteActionPlayNew value: 1];
				[[BRApplication sharedApplication] dispatchEventOnEventThread: event];
				break;
			}
			case XK_Delete:
			case XK_BackSpace:
			{
				NSString *eventStr = [NSString stringWithString: kBHVNCServerBackspaceString];
				NSDictionary *eventDict = [NSDictionary dictionaryWithObjectsAndKeys: eventStr, @"kBRKeyEventCharactersKey", nil];
				NSString *osBuild = [[BRSettingsFacade singleton] versionOSBuild];
				int eventAction = 48;
				if([osBuild isEqualToString: @"8M89"])
				{ eventAction = 47; }
				else if([osBuild isEqualToString: @"8C154"] || [osBuild isEqualToString: @"8C150"])
				{ eventAction = 48; }
				
				BREvent *event = [BREvent eventWithAction: eventAction value: 1 atTime: 0 originator: 0 eventDictionary: eventDict allowRetrigger: NO];
				[[BRApplication sharedApplication] dispatchEventOnEventThread: event];
				break;
			}
			default:
			{				
				NSCharacterSet *defaultSet = [NSCharacterSet characterSetWithCharactersInString: kBHVNCServerCharacterSet];
				if([defaultSet characterIsMember: keySym])
				{
					NSString *eventStr = [NSString stringWithFormat: @"%c", keySym];
					NSDictionary *eventDict = [NSDictionary dictionaryWithObjectsAndKeys: eventStr, @"kBRKeyEventCharactersKey", nil];
					NSString *osBuild = [[BRSettingsFacade singleton] versionOSBuild];
					int eventAction = 48;
					if([osBuild isEqualToString: @"8M89"])
					{ eventAction = 47; }
					else if([osBuild isEqualToString: @"8C154"] || [osBuild isEqualToString: @"8C150"])
					{ eventAction = 48; }
					
					BREvent *event = [BREvent eventWithAction: eventAction value: 1 atTime: 0 originator: 0 eventDictionary: eventDict allowRetrigger: NO];
					[[BRApplication sharedApplication] dispatchEventOnEventThread: event];
				}
				break;
			}
		}
	}
	[localPool drain];
}

@implementation BHVNCServer

#pragma mark -
#pragma mark Creation + Destruction
#pragma mark

- (id) init
{
	if(self = [super init])
	{
		[[NSNotificationCenter defaultCenter] addObserver: self selector: @selector(vncSettingsUpdated:) name: kVNCSettingsUpdatedNotification object: nil];
		_serverStarted = NO;
		usingFallback = YES;
		rfbServer = NULL;
	}
	return self;
}

- (void) dealloc
{
	[[NSNotificationCenter defaultCenter] removeObserver: self];
	[self stopServer];
	[_currentSettings.password release];
	[super dealloc];
}

#pragma mark -
#pragma mark Class Methods
#pragma mark

+ (id) sharedInstance
{
	static BHVNCServer *server = nil;
	if(!server)
	{ server = [[BHVNCServer alloc] init]; }
	return server;
}

+ (NSDictionary *) settingsDict
{ 
	NSString *settingsPath = [[NSString stringWithFormat: @"~/Library/Preferences/%@.plist", kBHVNCServerDomainID] stringByExpandingTildeInPath];
	NSDictionary *settings = [NSDictionary dictionaryWithContentsOfFile: settingsPath];
	if(!settings)
	{
		NSLog(@"Exposed -> settings not found, creating defaults...");
		settings = [NSDictionary dictionaryWithObjectsAndKeys:
										 [NSNumber numberWithBool: YES], kVNCSettingsEnabledKey,
										 [NSNumber numberWithBool: YES], kVNCSettingsDefaultScreenSizeKey,
										 [NSNumber numberWithBool: YES], kVNCSettingsKeepAspectRatioKey,
										 [NSNumber numberWithFloat: kBHVNCServerDefaultFrameWidth], kVNCSettingsScaledWidthKey,
										 [NSNumber numberWithFloat: kBHVNCServerDefaultFrameHeight], kVNCSettingsScaledHeightKey,
										 [NSNumber numberWithBool: NO], kVNCSettingsForceFallbackKey,
										 [NSString stringWithString: @""], kVNCSettingsVNCPasswordKey, nil];
		
		NSData *settingsData = [NSPropertyListSerialization dataWithPropertyList: settings format: NSPropertyListXMLFormat_v1_0 options: 0 error: nil];
		[settingsData writeToFile: settingsPath atomically: YES];
	}
	return settings;
}

#pragma mark -
#pragma mark Private Methods
#pragma mark

- (void) _markModifiedRectsInFrameBuffer1: (uint32_t *)fb1 frameBuffer2: (uint32_t *) fb2 width: (int) width height: (int) height
{
	CGSize cellSize = CGSizeMake(32, 32);
	int cellColumns = width / cellSize.width;
	int cellRows = height / cellSize.height;
	
	for(int r = 0; r < cellRows; r++)
	{
		for(int c = 0; c < cellColumns; c++)
		{
			CGPoint cellPoint;
			cellPoint.x = c * cellSize.width;
			cellPoint.y = r * cellSize.height;
			
			BOOL modified = NO;
			for(int y = cellPoint.y; y < (cellPoint.y + cellSize.height); y++)
			{
				for(int x = cellPoint.x; x < (cellPoint.x + cellSize.width); x++)
				{
					uint32_t pixel1 = fb1[x + (y * width)];
					uint32_t pixel2 = fb2[x + (y * width)];
					if(pixel1 != pixel2)
					{
						modified = YES;
						break;
					}
				}
				if(modified)
				{
					rfbMarkRectAsModified(rfbServer, 
										  cellPoint.x, 
										  cellPoint.y, 
										  (cellPoint.x + cellSize.width), 
										  (cellPoint.y + cellSize.height));
					break;
				}
			}
		}
	}
}

- (void) _refreshThread
{
	NSAutoreleasePool *localPool = [[NSAutoreleasePool alloc] init];
	
	int width = rfbServer->width;
	int height = rfbServer->height;
	int bytesPerComponent = 4;
	int bytesPerRow = width * bytesPerComponent;
	int allocSize = width * height * bytesPerComponent;
	OSType pixelFormat = 'BGRA';
	
	CALayer *screenLayer = [BRWindow rootLayer];
	uint32_t *layerBuffer = (uint32_t *)malloc(allocSize);
	
	CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
	CGContextRef layerBufferCtx = CGBitmapContextCreate(layerBuffer, width, height, 8, width * 4, colorSpace, kCGImageAlphaPremultipliedLast);
	CGContextScaleCTM(layerBufferCtx, (width / screenLayer.frame.size.width), (height / screenLayer.frame.size.height));
	rfbServer->frameBuffer = (char *)layerBuffer;
	
	NSMutableDictionary *surfaceDict = [NSMutableDictionary dictionary];
	[surfaceDict setObject: [NSNumber numberWithBool: NO] forKey: (NSString *)kIOSurfaceIsGlobal];
	[surfaceDict setObject: [NSNumber numberWithInt: bytesPerRow] forKey: (NSString *)kIOSurfaceBytesPerRow];
	[surfaceDict setObject: [NSNumber numberWithInt: bytesPerComponent] forKey: (NSString *)kIOSurfaceBytesPerElement];
	[surfaceDict setObject: [NSNumber numberWithInt: width] forKey: (NSString *)kIOSurfaceWidth];
	[surfaceDict setObject: [NSNumber numberWithInt: height] forKey: (NSString *)kIOSurfaceHeight];
	[surfaceDict setObject: [NSNumber numberWithInt: pixelFormat] forKey: (NSString *)kIOSurfacePixelFormat];
	[surfaceDict setObject: [NSNumber numberWithInt: allocSize] forKey: (NSString *)kIOSurfaceAllocSize];
	
	IOSurfaceAcceleratorRef accelerator;
	IOSurfaceRef convSurface;
	
	while(_serverStarted)
	{
		if(rfbServer->clientHead)
		{
			IOSurfaceRef screenSurface;
			if(!_currentSettings.forceFallback && (screenSurface = IOSurfaceLookup(1)))
			{
				if(usingFallback)
				{
					NSLog(@"Exposed -> switching to IOSurface...");
					rfbServer->serverFormat.redShift = 16;
					rfbServer->serverFormat.greenShift = 8;
					rfbServer->serverFormat.blueShift = 0;
					
					convSurface = IOSurfaceCreate((CFDictionaryRef)surfaceDict);
					IOSurfaceAcceleratorCreate(kCFAllocatorDefault, 0, &accelerator);
									
					IOSurfaceLock(convSurface, 1, NULL);
					rfbServer->frameBuffer = (char *)IOSurfaceGetBaseAddress(convSurface);
					IOSurfaceUnlock(convSurface, 1, NULL);
					usingFallback = NO;
				}
				IOSurfaceAcceleratorTransferSurface(accelerator, screenSurface, convSurface, (CFDictionaryRef)[NSDictionary dictionaryWithObjectsAndKeys: nil], NULL);
			}
			else
			{ [screenLayer renderInContext: layerBufferCtx]; }
			rfbMarkRectAsModified(rfbServer, 0, 0, rfbServer->width, rfbServer->height);
		}
		rfbProcessEvents(rfbServer, rfbServer->deferUpdateTime);
	}
	
	CGContextRelease(layerBufferCtx);
	CGColorSpaceRelease(colorSpace);
	free(layerBuffer);
	
	CFRelease(accelerator);
	CFRelease(convSurface);
	
	[localPool drain];
}

#pragma mark -
#pragma mark Public Methods
#pragma mark

- (void) prepareForLaunch
{
    [[NSNotificationCenter defaultCenter] removeObserver: self
                                                    name: @"DisplayColorMode"
                                                  object: nil];
    [self updateFromSettings];
}

- (void) updateFromSettings
{
	[self stopServer];
	
	NSDictionary *settingsDict = [BHVNCServer settingsDict];
	_currentSettings.enabled = [[settingsDict objectForKey: kVNCSettingsEnabledKey] boolValue];
	_currentSettings.defaultScreenSize = [[settingsDict objectForKey: kVNCSettingsDefaultScreenSizeKey] boolValue];
	_currentSettings.scaledWidth = [[settingsDict objectForKey: kVNCSettingsScaledWidthKey] floatValue];
	_currentSettings.scaledHeight = [[settingsDict objectForKey: kVNCSettingsScaledHeightKey] floatValue];
	_currentSettings.keepAspectRatio = [[settingsDict objectForKey: kVNCSettingsKeepAspectRatioKey] boolValue];
	_currentSettings.forceFallback = [[settingsDict objectForKey: kVNCSettingsForceFallbackKey] boolValue];
	
	[_currentSettings.password release];
	_currentSettings.password = [[settingsDict objectForKey: kVNCSettingsVNCPasswordKey] retain];
	
	if(_currentSettings.keepAspectRatio)
	{ _currentSettings.scaledHeight = _currentSettings.scaledWidth * kBHVNCServerDefaultFrameAspectRatio; }
	
	if(_currentSettings.defaultScreenSize)
	{
		_currentSettings.scaledWidth = kBHVNCServerDefaultFrameWidth;
		_currentSettings.scaledHeight = kBHVNCServerDefaultFrameHeight;
	}
	
	if(_currentSettings.enabled)
	{ [self startServer]; }
}

- (BOOL) serverStarted
{ return _serverStarted; }

- (void) startServer
{
	if(!_serverStarted)
	{		
		NSLog(@"Exposed -> starting server...");
		rfbServer = rfbGetScreen(0, NULL, _currentSettings.scaledWidth, _currentSettings.scaledHeight, 8, 3, 4);
		rfbServer->desktopName = "Exposed - AppleTV VNC Server";
		rfbServer->alwaysShared = TRUE;
		rfbServer->handleEventsEagerly = TRUE;
		rfbServer->deferUpdateTime = 40;
		rfbServer->cursor = NULL;
		rfbServer->kbdAddEvent = &kbdEvent;
		rfbServer->newClientHook = &newClient;
		
		if([_currentSettings.password length] > 0)
		{ 
			rfbServer->authPasswdData = _currentSettings.password;
			rfbServer->passwordCheck = &passCheck;
		}

		rfbInitServer(rfbServer);		
		_serverStarted = YES;
		usingFallback = YES;
		[NSThread detachNewThreadSelector: @selector(_refreshThread) toTarget: self withObject: nil];
		NSLog(@"Exposed -> server started :)");
	}
}

- (void) stopServer
{
	if(_serverStarted)
	{		
		rfbScreenCleanup(rfbServer);
		_serverStarted = NO;
		usingFallback = YES;
		NSLog(@"Exposed -> server stopped");
	}
}

- (BHVNCSettings) currentSettings
{ return _currentSettings; }

#pragma mark -
#pragma mark VNCSettings Notifications
#pragma mark

- (void) vncSettingsUpdated: (NSNotification *) notification
{
	NSLog(@"Exposed -> settings changed. updating...");
	[self updateFromSettings];
}

@end
