//
//  main.m
//  Exposed
//
//  Created by Brandon Holland on 10-12-20.
//  Copyright 2010 What a Nutbar Software. All rights reserved.
//

#import "BHVNCServer.h"
#import "substrate.h"

static IMP LTAppDelegate_completeNormalApplicationDidFinishLaunching_old;
void LTAppDelegate_completeNormalApplicationDidFinishLaunching_new(id self, SEL cmd)
{
    LTAppDelegate_completeNormalApplicationDidFinishLaunching_old(self, cmd);
    [[NSNotificationCenter defaultCenter] postNotificationName: kBHVNCServerShouldLaunchNotification 
                                                        object: nil];
}

MSInitialize
{
    NSAutoreleasePool *localPool = [[NSAutoreleasePool alloc] init];
    
	NSLog(@"Exposed -> version %@ loaded", kBHVNCServerVersionString);	
    [[NSNotificationCenter defaultCenter] addObserver: [BHVNCServer sharedInstance]
                                             selector: @selector(prepareForLaunch)
                                                 name: kBHVNCServerShouldLaunchNotification
                                               object: nil];
    
    MSHookMessageEx(NSClassFromString(@"LTAppDelegate"),
                    @selector(completeNormalApplicationDidFinishLaunching),
                    (IMP)LTAppDelegate_completeNormalApplicationDidFinishLaunching_new,
                    (IMP *)&LTAppDelegate_completeNormalApplicationDidFinishLaunching_old);
    
    [localPool drain];
}