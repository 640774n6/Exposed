//
//  main.m
//  Exposed
//
//  Created by Brandon Holland on 10-12-20.
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import "BHVNCServer.h"
#import "substrate.h"

MSInitialize
{
	NSLog(@"Exposed -> version %@ loaded", kBHVNCServerVersionString);	
	[[NSNotificationCenter defaultCenter] addObserver: [BHVNCServer sharedInstance] 
											 selector: @selector(prepareForLaunch) 
												 name: @"DisplayColorMode" 
											   object: nil];
}