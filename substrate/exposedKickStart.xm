
%hook LTAppDelegate


- (void)completeNormalApplicationDidFinishLaunching
{
%orig;
    [[NSNotificationCenter defaultCenter] postNotificationName:@"StartExposed" object:nil];
}

%end

