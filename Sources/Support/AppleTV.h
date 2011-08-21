/*
 *  AppleTV.h
 *  POC
 *
 *  Created by Brandon Holland on 10-09-30.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

@interface BRControlLayer: CALayer 
+ (id)defaultActionForKey:(id)key;	// 0x315d1519
@end

@interface BRWindow: NSObject 
+ (BOOL)dispatchEvent:(id)event;	// 0x315d47b5
+ (id)focusedLeafControl;	// 0x315d4789
+ (void)initialize;	// 0x315d49fd
+ (CGRect)interfaceFrame;	// 0x315d4d55
+ (CGSize)maxBounds;	// 0x315d4261
+ (id)rootLayer;	// 0x315d47e9
+ (void)setMaxBounds:(CGSize)bounds;	// 0x315d4d75
+ (id)window;	// 0x315a5b05
+ (id)windowList;	// 0x315d4285
- (id)init;	// 0x3158d535
- (void)_addWindow:(id)window atIndex:(long)index;	// 0x315d444d
- (id)_controlPlane;	// 0x315d4291
- (void)_orderWindow:(id)window above:(id)above;	// 0x315d44ed
- (void)_orderWindow:(id)window below:(id)below;	// 0x315d4585
- (void)_orderWindowBack:(id)back;	// 0x315d461d
- (void)_orderWindowFront:(id)front;	// 0x315d46a9
- (void)_orderWindowOut:(id)anOut;	// 0x315d4735
- (void)_updateContent;	// 0x315d4941
- (void)_updateRenderedWindows;	// 0x315d42a1
- (void)dealloc;	// 0x315a16c9
- (void)orderAbove:(id)above;	// 0x315d482d
- (void)orderBack;	// 0x315d489d
- (void)orderBelow:(id)below;	// 0x315d4865
- (void)orderFront;	// 0x3158d8d5
- (void)orderOut;	// 0x315a143d
@end


@interface BRControl: NSObject
+ (id)control;	// 0x3158e115
+ (id)controlWithScaledFrame:(CGRect)scaledFrame;	// 0x3161ebb5
+ (Class)layerClass;	// 0x315d25e9
- (id)init;	// 0x3158d5e1
- (BOOL)_changeFocusTo:(id)to;	// 0x3158da55
- (void)_dumpControlTree;	// 0x315d2d49
- (void)_dumpFocusTree;	// 0x315d2fb1
- (BOOL)_focusControlTreeForEvent:(id)event nearPoint:(CGPoint)point;	// 0x315a105d
- (BOOL)_focusControlTreeWithDefaults;	// 0x3158d9e1
- (id)_focusedLeafControl;	// 0x315a103d
- (CGPoint)_focusedPointForEvent:(id)event;	// 0x315a0f79
- (id)_initialFocus;	// 0x315d1715
- (void)_insertSingleControl:(id)control atIndex:(long)index;	// 0x315d17b5
- (void)_layoutSublayersOfLayer:(id)layer;	// 0x315d24bd
- (id)_parentScrollControl;	// 0x31671385
- (void)_reevaluateFocusTree;	// 0x3159c9f1
- (void)_removeAllControls;	// 0x315d1759
- (void)_removeControl:(id)control;	// 0x315961cd
- (void)_resizeSubviewsWithOldSize:(CGSize)oldSize;	// 0x315d30d1
- (void)_resizeWithOldSuperviewSize:(CGSize)oldSuperviewSize;	// 0x315d2c21
- (void)_scrollPoint:(CGPoint)point fromControl:(id)control;	// 0x31671351
- (void)_scrollRect:(CGRect)rect fromControl:(id)control;	// 0x31671301
- (void)_scrollingCompleted;	// 0x3167146d
- (void)_scrollingInitiated;	// 0x3167142d
- (void)_setControlFocused:(BOOL)focused;	// 0x3158d90d
- (void)_setFocus:(id)focus;	// 0x3158daed
- (CGRect)_visibleRectOfControl:(id)control;	// 0x31671add
- (void)_visibleScrollRectChanged;	// 0x316712d5
- (BOOL)acceptsFocus;	// 0x3158da45
- (id)actionForKey:(id)key;	// 0x315d19ad
- (id)actionForLayer:(id)layer forKey:(id)key;	// 0x315d24d1
- (id)actions;	// 0x315d196d
- (BOOL)active;	// 0x315d156d
- (void)addAnimation:(id)animation forKey:(id)key;	// 0x315d1a2d
- (void)addControl:(id)control;	// 0x315d22c5
- (CGAffineTransform)affineTransform;	// 0x315d27f5
- (CGPoint)anchorPoint;	// 0x315d2819
- (id)animationForKey:(id)key;	// 0x315d1a0d
- (unsigned)autoresizingMask;	// 0x315d155d
- (BOOL)avoidsCursor;	// 0x315a1465
- (CGColorRef)backgroundColor;	// 0x315d1f25
- (id)badge;	// 0x315e19c5
- (CGColorRef)borderColor;	// 0x315d1bc5
- (float)borderWidth;	// 0x315d1b85
- (CGRect)bounds;	// 0x315d283d
- (CGSize)boundsForFocusCandidate:(id)focusCandidate;	// 0x315d2609
- (BOOL)brEventAction:(id)action;	// 0x315a0ad9
- (BOOL)brKeyEvent:(id)event;	// 0x315d1539
- (int)contentMode;	// 0x315d1c05
- (long)controlCount;	// 0x315d2061
- (void)controlDidDisplayAsModalDialog;	// 0x315a6b8d
- (id)controlForPoint:(CGPoint)point;	// 0x315d15d5
- (void)controlWasActivated;	// 0x315d237d
- (void)controlWasDeactivated;	// 0x315d2341
- (void)controlWasFocused;	// 0x3158d941
- (void)controlWasUnfocused;	// 0x3159a58d
- (id)controls;	// 0x315d2091
- (CGPoint)convertPoint:(CGPoint)point fromControl:(id)control;	// 0x315d2761
- (CGPoint)convertPoint:(CGPoint)point toControl:(id)control;	// 0x315d2701
- (CGRect)convertRect:(CGRect)rect fromControl:(id)control;	// 0x315d26a9
- (CGRect)convertRect:(CGRect)rect toControl:(id)control;	// 0x315d2651
- (void)dealloc;	// 0x3159a085
- (id)debugDescriptionForFocusCandidate:(id)focusCandidate;	// 0x315d15dd
- (id)defaultFocus;	// 0x315d1585
- (void)drawInContext:(CGContextRef)context;	// 0x315d1581
- (void)drawLayer:(id)layer inContext:(CGContextRef)context;	// 0x315d24e9
- (BOOL)eligibilityForFocusCandidate:(id)focusCandidate;	// 0x315d16a1
- (id)firstControlNamed:(id)named;	// 0x315d3189
- (id)focusCandidates;	// 0x315d16f5
- (CGRect)focusCursorFrame;	// 0x31597101
- (id)focusObjectForCandidate:(id)candidate;	// 0x315d16dd
- (id)focusedControl;	// 0x3158dadd
- (id)focusedControlForEvent:(id)event focusPoint:(CGPoint *)point;	// 0x315a110d
- (CGRect)frame;	// 0x315d2979
- (id)identifier;	// 0x3158e565
- (id)inheritedValueForKey:(id)key;	// 0x315d2501
- (BOOL)inhibitsFocusForChildren;	// 0x315d1595
- (BOOL)inhibitsScrollFocusForChildren;	// 0x315d15bd
- (id)initialFocus;	// 0x315d1ab9
- (void)insertControl:(id)control above:(id)above;	// 0x315d2225
- (void)insertControl:(id)control atIndex:(long)index;	// 0x315d2291
- (void)insertControl:(id)control below:(id)below;	// 0x315d21d9
- (BOOL)isFocused;	// 0x3158da35
- (BOOL)isHidden;	// 0x315d1e9d
- (id)keyEventTargetControl;	// 0x315d153d
- (id)layer;	// 0x315d1529
- (id)layerForBacking;	// 0x315d259d
- (void)layoutSubcontrols;	// 0x315d157d
- (BOOL)masksToBounds;	// 0x315d1f65
- (id)name;	// 0x315d2301
- (id)object;	// 0x315a20b1
- (float)opacity;	// 0x315d1ee5
- (id)parent;	// 0x315d31b9
- (id)parentScrollControl;	// 0x316713a9
- (CGPoint)position;	// 0x315d2955
- (CGPoint)positionForFocusCandidate:(id)focusCandidate;	// 0x315d2635
- (id)preferredActionForKey:(id)key;	// 0x315d15d9
- (float)preferredCursorRadius;	// 0x315e19c1
- (void)removeAllAnimations;	// 0x315d19cd
- (void)removeAnimationForKey:(id)key;	// 0x315d19ed
- (void)removeFromParent;	// 0x315d2039
- (id)root;	// 0x315d31e9
- (void)scrollPoint:(CGPoint)point;	// 0x31671411
- (void)scrollRectToVisible:(CGRect)visible;	// 0x316713d1
- (void)scrollingCompleted;	// 0x31671131
- (void)scrollingInitiated;	// 0x31671135
- (id)selectionHandler;	// 0x315d1a4d
- (void)setAcceptsFocus:(BOOL)focus;	// 0x3158d661
- (void)setActions:(id)actions;	// 0x315d198d
- (void)setAffineTransform:(CGAffineTransform)transform;	// 0x315d23b9
- (void)setAnchorPoint:(CGPoint)point;	// 0x315d2405
- (void)setAutoresizingMask:(unsigned)mask;	// 0x315d154d
- (void)setAvoidsCursor:(BOOL)cursor;	// 0x3159618d
- (void)setBackgroundColor:(CGColorRef)color;	// 0x315d1f45
- (void)setBorderColor:(CGColorRef)color;	// 0x315d1be5
- (void)setBorderWidth:(float)width;	// 0x315d1ba5
- (void)setBounds:(CGRect)bounds;	// 0x315d2861
- (void)setContentMode:(int)mode;	// 0x315d1dc1
- (void)setControls:(id)controls;	// 0x315d20bd
- (void)setDefaultFocus:(id)focus;	// 0x3159720d
- (void)setDefaultFocusWithPoint:(CGPoint)point;	// 0x315d15d1
- (void)setFocusedControl:(id)control;	// 0x3158dbf5
- (void)setFrame:(CGRect)frame;	// 0x315d3239
- (void)setHidden:(BOOL)hidden;	// 0x315d1ec1
- (void)setIdentifier:(id)identifier;	// 0x31596d19
- (void)setInhibitsFocusForChildren:(BOOL)children;	// 0x315d1a8d
- (void)setInhibitsScrollFocusForChildren:(bool)children;	// 0x315d15a5
- (void)setKeyEventTargetControl:(id)control;	// 0x315d2445
- (void)setMasksToBounds:(BOOL)bounds;	// 0x315d1f89
- (void)setName:(id)name;	// 0x315d2321
- (void)setNeedsDisplay;	// 0x315d1ff9
- (void)setNeedsDisplayInRect:(CGRect)rect;	// 0x315d1fad
- (void)setNeedsLayout;	// 0x315d2019
- (void)setObject:(id)object;	// 0x3159e5f9
- (void)setOpacity:(float)opacity;	// 0x315d1f05
- (void)setPosition:(CGPoint)position;	// 0x315d2425
- (void)setSelectionHandler:(id)handler;	// 0x315d1a6d
- (void)setValue:(id)value forKey:(id)key cascade:(BOOL)cascade;	// 0x315d299d
- (void)setValue:(id)value forUndefinedKey:(id)undefinedKey;	// 0x315d255d
- (CGSize)sizeThatFits:(CGSize)fits;	// 0x315d27c1
- (void)sizeToFit;	// 0x315d2a6d
- (int)touchSensitivity;	// 0x315d15cd
- (id)valueForUndefinedKey:(id)undefinedKey;	// 0x315d257d
- (CGRect)visibleScrollRect;	// 0x31671b25
- (void)visibleScrollRectChanged;	// 0x316713bd
@end

@protocol BRTextField
- (void)setString:(id)string;
- (id)stringValue;
@end

@protocol BRTextFieldDelegate
- (void)textDidChange:(id)text;
- (void)textDidEndEditing:(id)text;
@end

@interface BRTextFieldControl: BRControl <BRTextField>
- (id)init;	// 0x31659229
- (id)_secureTextFromClearText;	// 0x31658e55
- (BOOL)brEventAction:(id)action;	// 0x31658e29
- (BOOL)brKeyEvent:(id)event;	// 0x31659379
- (id)characterDelegate;	// 0x31658dd9
- (void)dealloc;	// 0x316591bd
- (id)delegate;	// 0x31658db9
- (float)maxScrollPosition;	// 0x31658f8d
- (BOOL)needsScrollingInBounds:(CGRect)bounds;	// 0x31658fad
- (void)setCharacterDelegate:(id)delegate;	// 0x31658de9
- (void)setClearString:(id)string;	// 0x31658ff9
- (void)setDelegate:(id)delegate;	// 0x31658dc9
- (void)setDisplayString:(id)string;	// 0x31659049
- (void)setScrollPosition:(float)position;	// 0x31658f6d
- (void)setShowCursor:(BOOL)cursor;	// 0x31659189
- (void)setString:(id)string;	// 0x31658ee9
- (void)setTextAttributes:(id)attributes;	// 0x316590dd
- (void)setUseSecureText:(BOOL)text;	// 0x31659155
- (BOOL)showCursor;	// 0x31658df9
- (CGSize)sizeThatFits:(CGSize)fits;	// 0x3165933d
- (id)stringValue;	// 0x31658f3d
- (id)textAttributes;	// 0x31658e19
- (BOOL)useSecureText;	// 0x31658e09
@end

@interface BRTextEntryControl: BRControl
- (id)init;	// 0x315af1b9
- (id)initWithTextEntryStyle:(int)textEntryStyle;	// 0x315af18d
- (id)initWithTextEntryStyle:(int)textEntryStyle textField:(id)field;	// 0x31601f05
- (void)_addActionKeysRowForKeyboard:(id)keyboard;	// 0x31601b81
- (void)_addCustomizedTextFieldControls;	// 0x316017b5
- (void)_addMainKeyboardContainerForKeyboard:(id)keyboard;	// 0x31601d19
- (void)_addOrRemoveCandidatesContainer:(id)container;	// 0x31602451
- (id)_bestKeyboardLanguage:(int)language;	// 0x315ffedd
- (void)_customizeTextEntryControls;	// 0x31601851
- (void)_finalizeControlWasFocused;	// 0x31600085
- (void)_generateKeyEventWithCharacters:(id)characters;	// 0x31602ac1
- (void)_handleCharacterSelectionEvent:(id)event;	// 0x31600bd9
- (void)_handleCustomActionKeyEvent:(id)event;	// 0x31600c39
- (void)_handlePopupKeyboardEvent;	// 0x31602b8d
- (void)_inputActionAppendCandidate:(id)candidate;	// 0x3160098d
- (void)_inputActionAppendText:(id)text;	// 0x316009e9
- (void)_inputActionClearText:(id)text;	// 0x316008d5
- (void)_inputActionDeleteText:(id)text;	// 0x316029b5
- (void)_inputActionEscape:(id)escape;	// 0x31600285
- (void)_inputActionSwitchInputMethod:(id)method;	// 0x316002e5
- (void)_inputActionSwitchKeyboard:(id)keyboard;	// 0x316004b5
- (void)_invokeInputActionWithDictionary:(id)dictionary;	// 0x316028d1
- (BOOL)_keyboardFocusIsAtEdge:(int)edge;	// 0x31600175
- (id)_keyboardMappingData;	// 0x316034ed
- (void)_removeActionKeysRow;	// 0x31601b29
- (void)_removeCustomizedTextFieldControls;	// 0x31601755
- (void)_removePopupKeyboard;	// 0x31600ac9
- (void)_setActiveKeyboard:(id)keyboard;	// 0x31601ed9
- (void)_wrapAroundEdge:(int)edge;	// 0x31600c81
- (void)addSelectionHandlerForControl:(id)control forKeyboard:(id)keyboard;	// 0x315ffdc9
- (BOOL)brEventAction:(id)action;	// 0x315b0749
- (BOOL)canWrapHorizontally;	// 0x31601589
- (BOOL)canWrapVertically;	// 0x31601521
- (void)controlWasFocused;	// 0x3160011d
- (void)controlWasUnfocused;	// 0x31600049
- (void)dealloc;	// 0x315b3971
- (void)deviceKeyboardClose;	// 0x315ffd4d
- (void)deviceKeyboardMessageHandler:(id)handler;	// 0x315ff949
- (void)deviceKeyboardUpdate:(BOOL)update;	// 0x315ffbfd
- (void)layoutSubcontrols;	// 0x31601fbd
- (void)reset;	// 0x316012c9
- (void)setBackgroundColor:(CGColorRef)color;	// 0x315ffebd
- (void)setCanWrapHorizontally:(BOOL)horizontally;	// 0x31601545
- (void)setCanWrapVertically:(BOOL)vertically;	// 0x316014dd
- (void)setConstrainCursorToPopupKeyboard:(BOOL)popupKeyboard;	// 0x315ff939
- (void)setDeviceKeyboardTitle:(id)title subText:(id)text;	// 0x316015ad
- (void)setFocusToGlyphNamed:(id)glyphNamed;	// 0x31601135
- (void)setInitialText:(id)text;	// 0x31601369
- (void)setOutlineColor:(CGColorRef)color;	// 0x315ffe9d
- (void)setPopupBackgroundColor:(CGColorRef)color;	// 0x316034bd
- (void)setPopupOutlineColor:(CGColorRef)color;	// 0x3160348d
- (void)setPopupShadowStyle:(int)style;	// 0x315ff929
- (void)setShowUserEnteredText:(BOOL)text;	// 0x316013f5
- (void)setTabControl:(id)control;	// 0x3160142d
- (void)setTextEntryStyle:(int)style;	// 0x315afbb5
- (void)setTextField:(id)field;	// 0x316015f9
- (void)setTextFieldDelegate:(id)delegate;	// 0x315b00cd
- (void)setTextFieldLabel:(id)label;	// 0x315b00ed
- (CGSize)sizeThatFits:(CGSize)fits;	// 0x3160241d
- (void)startSpinning;	// 0x315b09ed
- (void)stopSpinning;	// 0x315b0a35
- (id)tabControl;	// 0x315ff919
- (int)textEntryStyle;	// 0x315ff8f9
- (id)textField;	// 0x315ff909
- (id)textFieldDelegate;	// 0x316013d5
@end



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

@interface BREvent: NSObject
+ (id)eventWithAction:(int)action value:(int)value;	// 0x315d558d
+ (id)eventWithAction:(int)action value:(int)value atTime:(double)time;	// 0x315d5545
+ (id)eventWithAction:(int)action value:(int)value atTime:(double)time originator:(unsigned)originator;	// 0x315d54f9
+ (id)eventWithAction:(int)action value:(int)value atTime:(double)time originator:(unsigned)originator eventDictionary:(id)dictionary allowRetrigger:(BOOL)retrigger;	// 0x315d54a5
+ (id)eventWithEvent:(id)event originator:(unsigned)originator;	// 0x315d5355
+ (id)eventWithEvent:(id)event originator:(unsigned)originator eventDictionary:(id)dictionary allowRetrigger:(BOOL)retrigger;	// 0x315d540d
- (id)initWithAction:(int)action value:(int)value;	// 0x315d5735
- (id)initWithAction:(int)action value:(int)value atTime:(double)time;	// 0x315d5329
- (id)initWithAction:(int)action value:(int)value atTime:(double)time originator:(unsigned)originator;	// 0x315d52ed
- (id)initWithAction:(int)action value:(int)value atTime:(double)time originator:(unsigned)originator eventDictionary:(id)dictionary allowRetrigger:(BOOL)retrigger;	// 0x315d560d
- (void)dealloc;	// 0x315d55c5
- (id)description;	// 0x315d512d
- (BOOL)isEqual:(id)equal;	// 0x315d50b1
- (void)makeRetriggerEvent;	// 0x315d5071
- (int)remoteAction;	// 0x315a0f59
- (BOOL)retriggerEvent;	// 0x315a0ac9
@end
	
@interface BRHIDEvent: BREvent
+ (id)eventWithPage:(unsigned short)page usage:(unsigned short)usage value:(int)value;	// 0x315d5939
+ (id)eventWithPage:(unsigned short)page usage:(unsigned short)usage value:(int)value atTime:(double)time;	// 0x315d597d
+ (id)eventWithPage:(unsigned short)page usage:(unsigned short)usage value:(int)value extendedSignature:(unsigned long long)signature;	// 0x315d59c9
+ (id)eventWithPage:(unsigned short)page usage:(unsigned short)usage value:(int)value extendedSignature:(unsigned long long)signature atTime:(double)time;	// 0x315d5a15
- (id)initWithPage:(unsigned short)page usage:(unsigned short)usage value:(int)value;	// 0x315d58fd
- (id)initWithPage:(unsigned short)page usage:(unsigned short)usage value:(int)value atTime:(double)time;	// 0x315d5881
- (id)initWithPage:(unsigned short)page usage:(unsigned short)usage value:(int)value extendedSignature:(unsigned long long)signature;	// 0x315d58b9
- (id)initWithPage:(unsigned short)page usage:(unsigned short)usage value:(int)value extendedSignature:(unsigned long long)signature atTime:(double)time;	// 0x315d5b79
- (id)description;	// 0x315d5a69
- (BOOL)isEqual:(id)equal;	// 0x315d579d
@end

@interface BRSingleton: NSObject
+ (id)sharedInstance;
@end

@protocol BRAppliance
- (id)applianceCategories;
- (id)identifierForContentAlias:(id)fp8;
- (BOOL)handleObjectSelection:(id)fp8 userInfo:(id)fp12;
- (id)topShelfController;
@end

@interface BRBaseAppliance: NSObject <BRAppliance>
- (id)applianceCategories;
- (id)identifierForContentAlias:(id)fp8;
- (BOOL)handleObjectSelection:(id)fp8 userInfo:(id)fp12;
- (id)alertControllerForNoContent;
- (int)noContentBRError;
- (id)alertControllerForNoRemoteContent;
- (int)noRemoteContentBRError;
- (BOOL)previewError;
- (id)previewErrorText;
- (id)previewErrorSubtext;
- (id)previewErrorIconImage;
- (id)topShelfController;
- (id)_applianceCategories;
- (BOOL)_isCategoryWithIdentifier:(id)fp8 memberOfMusicStoreCollection:(id)fp12;
- (BOOL)_anySharesAvailable;
- (BOOL)_anyStoreCategoryExistsInMusicStoreCollection:(id)fp8;
@end

@interface ATVMusicStoreBaseAppliance: BRBaseAppliance
- (id)init;
- (void)dealloc;
- (void)applianceChanged:(id)fp8;
- (id)controllerForIdentifier:(id)fp8 args:(id)fp12;
- (id)applianceSpecificControllerForIdentifier:(id)fp8 args:(id)fp12;
- (id)localizedSearchTitle;
- (id)applianceCategoryDescriptions;
- (void)_refreshCategories:(id)fp8;
- (void)_storeLoadStateChanged:(id)fp8;
- (id)_qualifyRemoteCategoryDescription:(id)fp8;
@end

@interface BRApplianceInfo: NSObject
+ (id)infoForApplianceBundle:(id)fp8;
- (void)setPrimaryAppliance:(BOOL)fp8;
- (BOOL)primaryAppliance;
- (void)setIconPath:(id)fp8;
- (id)iconPath;
- (void)setIconHorizontalOffset:(float)fp8;
- (float)iconHorizontalOffset;
- (void)setIconKerningFactor:(float)fp8;
- (float)iconKerningFactor;
- (void)setIconReflectionOffset:(float)fp8;
- (float)iconReflectionOffset;
- (BOOL)appliesToMediaHost:(id)fp8;
- (void)setDataSourceType:(id)fp8;
- (id)dataSourceType;
- (void)setSupportedMediaTypes:(id)fp8;
- (id)supportedMediaTypes;
- (void)setRequiredRemoteMediaTypes:(id)fp8;
- (id)requiredRemoteMediaTypes;
- (void)setPrincipalClassName:(id)fp8;
- (id)principalClassName;
- (void)setApplianceCategoryDescriptors:(id)fp8;
- (void)setHideIfNoCategories:(BOOL)fp8;
- (BOOL)hideIfNoCategories;
- (void)setIsRemoteAppliance:(BOOL)fp8;
- (BOOL)isRemoteAppliance;
- (void)setPreferredOrder:(float)fp8;
- (float)preferredOrder;
@end

@interface BRApplianceManager: BRSingleton
- (void)loadAppliances;
- (id)applianceForInfo:(id)fp8;
- (id)controllerForApplianceInfo:(id)fp8 identifier:(id)fp12 args:(id)fp16;
- (id)controllerForContentAlias:(id)fp8;
- (id)_controllerForApplianceKey:(id)fp8 identifier:(id)fp12 args:(id)fp16;
- (BOOL)_handlePlay:(id)fp8 userInfo:(id)fp12;
- (void)_unloadCurrentAppliances;
- (id)_applianceForInfo:(id)fp8;
- (void)_loadAppliancesInFolder:(id)fp8;
- (void)_loadApplianceAtPath:(id)fp8;
- (id)controllerForApplianceKey:(id)fp8 identifier:(id)fp12 args:(id)fp16;
- (id)applianceInfoList;
- (BOOL)handleObjectSelection:(id)fp8 userInfo:(id)fp12;
@end

@interface BRApplication: NSObject
+ (id)sharedApplication;	// 0x31590b3d
- (id)init;	// 0x31590b81
- (void)_blockEvents;	// 0x31626f4d
- (void)_drainRunLoopPool;	// 0x31626fed
- (void)_handler;	// 0x31627711
- (void)_registerForEvents;	// 0x316279a1
- (void)_retriggerEvent:(id)event;	// 0x31626f99
- (void)_run;	// 0x316275d5
- (void)_setRetainedDelegate:(id)delegate;	// 0x31626f5d
- (void)_unblockEvents;	// 0x31627091
- (void)cancelRetriggerCurrentEvent;	// 0x316270bd
- (void)dealloc;	// 0x31627291
- (void)dispatchEventOnEventThread:(id)thread;	// 0x31627205
- (void)emptyQueue;	// 0x316274fd
- (void)postEvent:(id)event;	// 0x316273c1
- (void)retriggerCurrentEvent;	// 0x316271e9
- (void)retriggerCurrentEventAfterDelay:(double)delay;	// 0x31627105
- (void)retriggerCurrentEventWithDecreasingDelay;	// 0x3162718d
- (void)terminate;	// 0x31627305
@end

@interface BRSettingsFacade : BRSingleton {
}
@property(assign) BOOL UISoundsEnabled;	// G=0x30e37c21; S=0x30e37ba1; converted property
@property(assign) int audioFormatSetting;	// G=0x30e37745; S=0x30e376ed; converted property
@property(assign) BOOL crashReportingEnabled;	// G=0x30e38031; S=0x30e37fb5; converted property
@property(retain) id defaultAudioLanguage;	// G=0x30e37a45; S=0x30e379ed; converted property
@property(retain) id defaultSubtitleLanguage;	// G=0x30e37ad5; S=0x30e37a7d; converted property
@property(assign) int favoritesSortMode;	// G=0x30e37525; S=0x30e374e9; converted property
@property(retain) id keyboardLanguageKeys;	// G=0x30e36b39; S=0x30e36b01; converted property
@property(retain) id lastUsedKeyboardLanguage;	// G=0x30e36a65; S=0x30e36a2d; converted property
@property(retain) id marimbaSlideshowDefaultMusicPlaylistID;	// G=0x30e36ba5; S=0x30e36b6d; converted property
@property(retain) id marimbaSlideshowDefaultMusicServerID;	// G=0x30e36c11; S=0x30e36bd9; converted property
@property(retain) id marimbaSlideshowStyle;	// G=0x30e36d41; S=0x30e36d81; converted property
@property(assign) int musicRepeatMode;	// G=0x30da3431; S=0x30e37911; converted property
@property(assign) BOOL musicVolumeControlEnabled;	// G=0x30e378d5; S=0x30e3784d; converted property
@property(assign) BOOL playlistsEverywhereEnabled;	// G=0x30e37675; S=0x30e37639; converted property
@property(assign) BOOL preferHDVideo;	// G=0x30e375c1; S=0x30e37561; converted property
@property(assign) BOOL screenSaverAllowedOverMusic;	// G=0x30da4935; S=0x30e375fd; converted property
@property(assign) BOOL slideshowPanAndZoom;	// G=0x30e37215; S=0x30e371d9; converted property
@property(assign) BOOL slideshowPlayMusic;	// G=0x30e3719d; S=0x30e37161; converted property
@property(assign) BOOL slideshowRepeat;	// G=0x30e3737d; S=0x30e37341; converted property
@property(assign) int slideshowSecondsPerSlide;	// G=0x30e3741d; S=0x30e373e1; converted property
@property(retain) id slideshowSelectedPlaylistName;	// G=0x30e36f61; S=0x30e36f29; converted property
@property(retain) id slideshowSelectedTransitionName;	// G=0x30e36ecd; S=0x30e36e91; converted property
@property(assign) BOOL slideshowShuffleMusic;	// G=0x30e3728d; S=0x30e37251; converted property
@property(assign) BOOL slideshowShufflePhotos;	// G=0x30e37305; S=0x30e372c9; converted property
@property(retain) id slideshowTransitionDirection;	// G=0x30e36e15; S=0x30e36dd9; converted property
@property(assign) int videoClosedCaptionMode;	// G=0x30d92785; S=0x30e37b35; converted property
+ (void)setSingleton:(id)singleton;	// 0x30d75659
+ (id)singleton;	// 0x30d75589
// converted property getter: - (BOOL)UISoundsEnabled;	// 0x30e37c21
- (id)_availableDefaultAVLanguages;	// 0x30e36389
- (long)_preferredTrackIDForMedia:(id)media forType:(id)type;	// 0x30e366d9
- (void)_removeSavedPreferredTrackIDsForType:(id)type;	// 0x30e36461
- (void)_savePreferredTrackID:(long)anId forMedia:(id)media forType:(id)type;	// 0x30e364cd
- (void)_setSlideshowSelectedPlaylistName:(id)name forHost:(id)host;	// 0x30e36841
- (id)_slideshowSelectedPlaylistNameForHost:(id)host;	// 0x30e36771
// converted property getter: - (int)audioFormatSetting;	// 0x30e37745
- (id)availableDefaultAudioLanguages;	// 0x30e37b0d
- (id)availableDefaultSubtitleLanguages;	// 0x30e37b21
- (BOOL)bootedFromRecoveryPartition;	// 0x30e36381
// converted property getter: - (BOOL)crashReportingEnabled;	// 0x30e38031
- (BOOL)crashReportingPreferenceSet;	// 0x30e376b1
// converted property getter: - (id)defaultAudioLanguage;	// 0x30e37a45
// converted property getter: - (id)defaultSubtitleLanguage;	// 0x30e37ad5
// converted property getter: - (int)favoritesSortMode;	// 0x30e37525
- (void)flushDiskChanges;	// 0x30d7704d
- (id)hwDeviceName;	// 0x30e3697d
- (BOOL)keyboardLanguageEnabled:(id)enabled;	// 0x30e36acd
// converted property getter: - (id)keyboardLanguageKeys;	// 0x30e36b39
// converted property getter: - (id)lastUsedKeyboardLanguage;	// 0x30e36a65
// converted property getter: - (id)marimbaSlideshowDefaultMusicPlaylistID;	// 0x30e36ba5
// converted property getter: - (id)marimbaSlideshowDefaultMusicServerID;	// 0x30e36c11
// converted property getter: - (id)marimbaSlideshowStyle;	// 0x30e36d41
// converted property getter: - (int)musicRepeatMode;	// 0x30da3431
- (float)musicVolume;	// 0x30e37811
// converted property getter: - (BOOL)musicVolumeControlEnabled;	// 0x30e378d5
- (id)parentalControlsPasscode;	// 0x30e374b1
- (int)parentalControlsYTMode;	// 0x30e37479
// converted property getter: - (BOOL)playlistsEverywhereEnabled;	// 0x30e37675
// converted property getter: - (BOOL)preferHDVideo;	// 0x30e375c1
- (long)preferredAlternateAudioTrackIDForMedia:(id)media;	// 0x30e37981
- (long)preferredSubtitleTrackIDForMedia:(id)media;	// 0x30e379cd
- (void)resetAllSettings;	// 0x30e37c8d
- (BOOL)saveConfiguration:(id)configuration;	// 0x30e36385
- (void)saveMusicVolume:(float)volume;	// 0x30e377a9
- (void)savePreferredAlternateAudioTrackID:(long)anId forMedia:(id)media;	// 0x30e37955
- (void)savePreferredSubtitleTrackID:(long)anId forMedia:(id)media;	// 0x30e379a1
// converted property getter: - (BOOL)screenSaverAllowedOverMusic;	// 0x30da4935
// converted property setter: - (void)setAudioFormatSetting:(int)setting;	// 0x30e376ed
// converted property setter: - (void)setCrashReportingEnabled:(BOOL)enabled;	// 0x30e37fb5
// converted property setter: - (void)setDefaultAudioLanguage:(id)language;	// 0x30e379ed
// converted property setter: - (void)setDefaultSubtitleLanguage:(id)language;	// 0x30e37a7d
// converted property setter: - (void)setFavoritesSortMode:(int)mode;	// 0x30e374e9
- (void)setHWDeviceName:(id)name;	// 0x30e38095
- (void)setKeyboardLanguageEnabled:(id)enabled enabled:(BOOL)enabled2;	// 0x30e36a99
// converted property setter: - (void)setKeyboardLanguageKeys:(id)keys;	// 0x30e36b01
// converted property setter: - (void)setLastUsedKeyboardLanguage:(id)language;	// 0x30e36a2d
// converted property setter: - (void)setMarimbaSlideshowDefaultMusicPlaylistID:(id)anId;	// 0x30e36b6d
// converted property setter: - (void)setMarimbaSlideshowDefaultMusicServerID:(id)anId;	// 0x30e36bd9
// converted property setter: - (void)setMarimbaSlideshowStyle:(id)style;	// 0x30e36d81
// converted property setter: - (void)setMusicRepeatMode:(int)mode;	// 0x30e37911
// converted property setter: - (void)setMusicVolumeControlEnabled:(BOOL)enabled;	// 0x30e3784d
// converted property setter: - (void)setPlaylistsEverywhereEnabled:(BOOL)enabled;	// 0x30e37639
// converted property setter: - (void)setPreferHDVideo:(BOOL)video;	// 0x30e37561
// converted property setter: - (void)setScreenSaverAllowedOverMusic:(BOOL)music;	// 0x30e375fd
// converted property setter: - (void)setSlideshowPanAndZoom:(BOOL)zoom;	// 0x30e371d9
// converted property setter: - (void)setSlideshowPlayMusic:(BOOL)music;	// 0x30e37161
// converted property setter: - (void)setSlideshowRepeat:(BOOL)repeat;	// 0x30e37341
// converted property setter: - (void)setSlideshowSecondsPerSlide:(int)slide;	// 0x30e373e1
// converted property setter: - (void)setSlideshowSelectedPlaylistName:(id)name;	// 0x30e36f29
// converted property setter: - (void)setSlideshowSelectedTransitionName:(id)name;	// 0x30e36e91
// converted property setter: - (void)setSlideshowShuffleMusic:(BOOL)music;	// 0x30e37251
// converted property setter: - (void)setSlideshowShufflePhotos:(BOOL)photos;	// 0x30e372c9
// converted property setter: - (void)setSlideshowTransitionDirection:(id)direction;	// 0x30e36dd9
// converted property setter: - (void)setUISoundsEnabled:(BOOL)enabled;	// 0x30e37ba1
// converted property setter: - (void)setVideoClosedCaptionMode:(int)mode;	// 0x30e37b35
// converted property getter: - (BOOL)slideshowPanAndZoom;	// 0x30e37215
// converted property getter: - (BOOL)slideshowPlayMusic;	// 0x30e3719d
- (id)slideshowPlaybackOptions;	// 0x30e36db9
- (id)slideshowPlaylists;	// 0x30e36f95
// converted property getter: - (BOOL)slideshowRepeat;	// 0x30e3737d
// converted property getter: - (int)slideshowSecondsPerSlide;	// 0x30e3741d
// converted property getter: - (id)slideshowSelectedPlaylistName;	// 0x30e36f61
// converted property getter: - (id)slideshowSelectedTransitionName;	// 0x30e36ecd
// converted property getter: - (BOOL)slideshowShuffleMusic;	// 0x30e3728d
// converted property getter: - (BOOL)slideshowShufflePhotos;	// 0x30e37305
// converted property getter: - (id)slideshowTransitionDirection;	// 0x30e36e15
- (id)slideshowTransitionNames;	// 0x30e36361
- (BOOL)slideshowTransitionsDisabled;	// 0x30e36365
- (BOOL)slideshowTransitionsRandom;	// 0x30e36369
- (id)syncHostName;	// 0x30e369f5
- (void)updateHostID:(id)anId to:(id)to;	// 0x30e37ef9
- (id)versionEFI;	// 0x30e36375
- (id)versionGF;	// 0x30e3637d
- (id)versionIR;	// 0x30e36379
- (id)versionOS;	// 0x30e3636d
- (id)versionOSBuild;	// 0x30e36371
- (id)versionSoftware;	// 0x30d787e5
- (id)versionSoftwareBuild;	// 0x30d7572d
// converted property getter: - (int)videoClosedCaptionMode;	// 0x30d92785
@end