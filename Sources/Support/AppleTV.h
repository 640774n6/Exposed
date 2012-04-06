
typedef enum {
	// for originator kBREventOriginatorRemote
	kBREventRemoteActionMenu = 1,
	kBREventRemoteActionMenuHold,
	kBREventRemoteActionUp,
	kBREventRemoteActionDown,
	kBREventRemoteActionPlay,
	kBREventRemoteActionLeft,
	kBREventRemoteActionRight,
	
	kBREventRemoteActionPlayNew = 10,
	kBREventRemoteActionPlayHold = 20,
	
	// Gestures, for originator kBREventOriginatorGesture
	kBREventRemoteActionTouchBegin = 30,
	kBREventRemoteActionTouchMove,
	kBREventRemoteActionTouchEnd,
	kBREventRemoteActionSwipeLeft,
	kBREventRemoteActionSwipeRight,
	kBREventRemoteActionSwipeUp,
	kBREventRemoteActionSwipeDown,
	
	// Custom remote actions for old remote actions
	kBREventRemoteActionHoldLeft = 0xfeed0001,
	kBREventRemoteActionHoldRight,
	kBREventRemoteActionHoldUp,
	kBREventRemoteActionHoldDown,
} BREventRemoteAction;

//AppleTV Header

@interface BRSingleton : NSObject
+ (id)allocWithZone:(NSZone *)zone;	// 0x3037190d
+ (id)sharedInstance;	// 0x30371809
- (id)autorelease;	// 0x303719e9
- (id)copyWithZone:(NSZone *)zone;	// 0x303719dd
- (oneway void)release;	// 0x303719e5
- (id)retain;	// 0x303719e1
- (unsigned)retainCount;	// 0x303719ed
@end

@interface BRApplication: NSObject
+ (id)sharedApplication;	// 0x303255ad
- (id)init;	// 0x303255f5
- (BOOL)_b39PlayPauseHoldTimerFired;	// 0x30326d89
- (void)_blockEvents;	// 0x30325e05
- (void)_drainRunLoopPool;	// 0x30326341
- (id)_endOfEventSelectorsByObserver;	// 0x303263a1
- (void)_handleB39PlayPauseTimerFire:(id)fire;	// 0x30326d65
- (void)_handler;	// 0x30326051
- (void)_registerForEvents;	// 0x30326411
- (void)_retriggerEvent:(id)event;	// 0x303263b1
- (void)_run;	// 0x30325e4d
- (void)_setB39PlayPauseHoldTimer:(id)timer;	// 0x30326d29
- (void)_unblockEvents;	// 0x30325e19
- (void)cancelRetriggerCurrentEvent;	// 0x30325c4d
- (id)currentEvent;	// 0x30325881
- (void)dealloc;	// 0x30325735
- (id)delegate;	// 0x30325dad
- (void)dispatchEventOnEventThread:(id)thread;	// 0x303259ed
- (void)emptyQueue;	// 0x30325a1d
- (id)firstResponder;	// 0x30325de5
- (BOOL)isInModalLoop;	// 0x30325b19
- (BOOL)isTerminating;	// 0x30325871
- (double)nextRetriggerDelay;	// 0x30325d95
- (void)postEvent:(id)event;	// 0x30325891
- (long)retriggerCount;	// 0x30325d85
- (void)retriggerCurrentEvent;	// 0x30325b29
- (void)retriggerCurrentEventAfterDelay:(double)delay;	// 0x30325ba9
- (void)retriggerCurrentEventWithDecreasingDelay;	// 0x30325b41
- (void)setDelegate:(id)delegate;	// 0x30325dc1
- (void)setFirstResponder:(id)responder;	// 0x30325df5
- (void)setIsInModalLoop:(BOOL)modalLoop;	// 0x30325b09
- (void)terminate;	// 0x3032579d
@end

@interface BREvent: NSObject
+ (id)eventWithAction:(int)action value:(int)value;	// 0x3026d031
+ (id)eventWithAction:(int)action value:(int)value atTime:(double)time;	// 0x3026d071
+ (id)eventWithAction:(int)action value:(int)value atTime:(double)time originator:(unsigned)originator;	// 0x3026d0bd
+ (id)eventWithAction:(int)action value:(int)value atTime:(double)time originator:(unsigned)originator eventDictionary:(id)dictionary allowRetrigger:(BOOL)retrigger;	// 0x3026d10d
+ (id)eventWithEvent:(id)event originator:(unsigned)originator;	// 0x3026d205
+ (id)eventWithEvent:(id)event originator:(unsigned)originator eventDictionary:(id)dictionary allowRetrigger:(BOOL)retrigger;	// 0x3026d169
- (id)initWithAction:(int)action value:(int)value;	// 0x3026d2c9
- (id)initWithAction:(int)action value:(int)value atTime:(double)time;	// 0x3026d2fd
- (id)initWithAction:(int)action value:(int)value atTime:(double)time originator:(unsigned)originator;	// 0x3026d329
- (id)initWithAction:(int)action value:(int)value atTime:(double)time originator:(unsigned)originator eventDictionary:(id)dictionary allowRetrigger:(BOOL)retrigger;	// 0x3026d365
- (BOOL)allowRetrigger;	// 0x3026d771
- (void)dealloc;	// 0x3026d411
- (id)description;	// 0x3026d45d
- (id)eventDictionary;	// 0x3026d761
- (BOOL)isEqual:(id)equal;	// 0x3026d671
- (void)makeRetriggerEvent;	// 0x3026d725
- (unsigned)originator;	// 0x3026d751
- (int)remoteAction;	// 0x3026d6f5
- (BOOL)retriggerEvent;	// 0x3026d715
- (double)timeStamp;	// 0x3026d739
- (int)value;	// 0x3026d705
@end

@interface BRWindow: NSObject
+ (void)_controlWasFocused:(id)focused;	// 0x3023f0e5
+ (void)_establishRootContext;	// 0x3023e7dd
+ (void)_establishRootLayerBounds;	// 0x3023ebc1
+ (void)adjustToDisplayChange;	// 0x3023e345
+ (BOOL)dispatchEvent:(id)event;	// 0x3023f055
+ (id)focusedControl;	// 0x3023e7cd
+ (id)focusedLeafControl;	// 0x3023f0b9
+ (void)initialize;	// 0x3023e1cd
+ (CGRect)interfaceFrame;	// 0x3023e325
+ (BOOL)makeFocusedControl:(id)control;	// 0x3023e7c9
+ (CGSize)maxBounds;	// 0x3023e311
+ (id)rootLayer;	// 0x3023eec9
+ (void)setMaxBounds:(CGSize)bounds;	// 0x3023eef5
+ (id)window;	// 0x3023e2d9
+ (id)windowList;	// 0x3023eee5
- (id)init;	// 0x3023e399
- (void)_addWindow:(id)window atIndex:(long)index;	// 0x3023f41d
- (id)_controlPlane;	// 0x3023f131
- (void)_orderWindow:(id)window above:(id)above;	// 0x3023f371
- (void)_orderWindow:(id)window below:(id)below;	// 0x3023f2c9
- (void)_orderWindowBack:(id)back;	// 0x3023f235
- (void)_orderWindowFront:(id)front;	// 0x3023f1a1
- (void)_orderWindowOut:(id)anOut;	// 0x3023f141
- (void)_updateContent;	// 0x3023f671
- (void)_updateRenderedWindows;	// 0x3023f4cd
- (BOOL)acceptsFocus;	// 0x3023e781
- (id)content;	// 0x3023e57d
- (void)dealloc;	// 0x3023e449
- (BOOL)dispatchEvent:(id)event;	// 0x3023e7c5
- (BOOL)isOpaque;	// 0x3023e7a5
- (BOOL)isOrderedIn;	// 0x3023e7b5
- (int)level;	// 0x3023e5d1
- (void)orderAbove:(id)above;	// 0x3023e6d9
- (void)orderBack;	// 0x3023e655
- (void)orderBelow:(id)below;	// 0x3023e695
- (void)orderFront;	// 0x3023e615
- (void)orderOut;	// 0x3023e5e1
- (void)setAcceptsFocus:(BOOL)focus;	// 0x3023e761
- (void)setContent:(id)content;	// 0x3023e4d9
- (void)setIsOpaque:(BOOL)opaque;	// 0x3023e71d
- (void)setLevel:(int)level;	// 0x3023e58d
@end


@interface ATVSettingsFacade: BRSingleton
+ (void)setSingleton:(id)singleton;	// 0x301b875d
+ (id)singleton;	// 0x301b874d
- (id)versionEFI;	// 0x301bc4a5
- (id)versionGF;	// 0x301bc55d
- (id)versionIR;	// 0x301bc541
- (id)versionOS;	// 0x301bc46d
- (id)versionOSBuild;	// 0x301bc489
- (id)versionSoftware;	// 0x301bc3b5
- (id)versionSoftwareBuild;	// 0x301bc405
@end

