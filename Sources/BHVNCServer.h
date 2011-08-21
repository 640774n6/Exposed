//
//  BHVNCServer.h
//  Exposed
//
//  Created by Brandon Holland on 10-10-10.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#include "rfb.h"
#include "keysym.h"

#define kBHVNCServerVersionString					@"0.6"
#define kBHVNCServerDomainID						@"com.whatanutbar.exposed"
#define kBHVNCServerCharacterSet					@"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ`1234567890-=[]\\;',./~!@#$%^&*()_+{}|:\"<>?\t "
#define kBHVNCServerBackspaceString					@"\uf73e"
#define kBHVNCServerDefaultFrameWidth				1280.0
#define kBHVNCServerDefaultFrameHeight				720.0
#define kBHVNCServerDefaultFrameAspectRatio			720.0 / 1280.0
#define kBHVNCServerClientConnectedNotification		@"BHVNCServerClientConnected"
#define kBHVNCServerClientDisconnectedNotification	@"BHVNCServerClientDisconnected"

#define kVNCSettingsEnabledKey						@"Enabled"
#define kVNCSettingsDefaultScreenSizeKey			@"DefaultScreenSize"
#define kVNCSettingsKeepAspectRatioKey				@"KeepAspectRatio"
#define kVNCSettingsScaledWidthKey					@"ScaledWidth"
#define kVNCSettingsScaledHeightKey					@"ScaledHeight"
#define kVNCSettingsForceFallbackKey				@"ForceFallback"
#define kVNCSettingsVNCPasswordKey					@"VNCPassword"
#define kVNCSettingsUpdatedNotification				@"VNCSettingsUpdated"

typedef struct
{
	BOOL enabled;
	BOOL defaultScreenSize;
	BOOL keepAspectRatio;
	CGFloat scaledWidth;
	CGFloat scaledHeight;
	BOOL forceFallback;
	NSString *password;
} BHVNCSettings;

@interface BHVNCServer: NSObject 
{
	rfbScreenInfoPtr rfbServer;
	BHVNCSettings _currentSettings;
	BOOL _serverStarted;
	BOOL usingFallback;
}
+ (id) sharedInstance;
+ (NSDictionary *) settingsDict;
- (void) prepareForLaunch;
- (void) updateFromSettings;
- (void) startServer;
- (void) stopServer;
- (BHVNCSettings) currentSettings;
@end
