#include <CoreFoundation/CFBase.h>

extern const CFStringRef kIOSurfaceAllocSize;
extern const CFStringRef kIOSurfaceWidth;
extern const CFStringRef kIOSurfaceHeight;
extern const CFStringRef kIOSurfaceBytesPerRow;
extern const CFStringRef kIOSurfaceBytesPerElement;
extern const CFStringRef kIOSurfaceElementWidth;
extern const CFStringRef kIOSurfaceElementHeight;
extern const CFStringRef kIOSurfaceOffset;
extern const CFStringRef kIOSurfacePlaneInfo;
extern const CFStringRef kIOSurfacePlaneWidth;
extern const CFStringRef kIOSurfacePlaneHeight;
extern const CFStringRef kIOSurfacePlaneBytesPerRow;
extern const CFStringRef kIOSurfacePlaneOffset;
extern const CFStringRef kIOSurfacePlaneSize;
extern const CFStringRef kIOSurfacePlaneBase;
extern const CFStringRef kIOSurfacePlaneBytesPerElement;
extern const CFStringRef kIOSurfacePlaneElementWidth;
extern const CFStringRef kIOSurfacePlaneElementHeight;
extern const CFStringRef kIOSurfaceCacheMode;
extern const CFStringRef kIOSurfaceIsGlobal;
extern const CFStringRef kIOSurfacePixelFormat;

typedef void * IOSurfaceRef;
typedef void * IOSurfaceAcceleratorRef;
typedef uint32_t IOSurfaceID;
typedef int IOSurfaceReturn;
typedef int IOSurfaceAcceleratorReturn;

CFTypeID IOSurfaceGetTypeID(void);
IOSurfaceRef IOSurfaceCreate(CFDictionaryRef properties);
IOSurfaceRef IOSurfaceLookup(IOSurfaceID csid);
IOSurfaceID IOSurfaceGetID(IOSurfaceRef buffer);

IOSurfaceReturn IOSurfaceLock(IOSurfaceRef buffer, uint32_t options, uint32_t *seed);
IOSurfaceReturn IOSurfaceUnlock(IOSurfaceRef buffer, uint32_t options, uint32_t *seed);

IOSurfaceAcceleratorReturn IOSurfaceAcceleratorCreate(CFAllocatorRef allocator, uint32_t type, IOSurfaceAcceleratorRef *outAccelerator);
IOSurfaceAcceleratorReturn IOSurfaceAcceleratorTransferSurface(IOSurfaceAcceleratorRef accelerator, IOSurfaceRef sourceSurface, IOSurfaceRef destSurface, CFDictionaryRef dict, void *unknown);

size_t IOSurfaceGetAllocSize(IOSurfaceRef buffer);
size_t IOSurfaceGetWidth(IOSurfaceRef buffer);
size_t IOSurfaceGetHeight(IOSurfaceRef buffer);
size_t IOSurfaceGetBytesPerElement(IOSurfaceRef buffer);
size_t IOSurfaceGetBytesPerRow(IOSurfaceRef buffer);
void *IOSurfaceGetBaseAddress(IOSurfaceRef buffer);
size_t IOSurfaceGetElementWidth(IOSurfaceRef buffer);
size_t IOSurfaceGetElementHeight(IOSurfaceRef buffer);
OSType IOSurfaceGetPixelFormat(IOSurfaceRef buffer);

uint32_t IOSurfaceGetSeed(IOSurfaceRef buffer);
size_t IOSurfaceGetPlaneCount(IOSurfaceRef buffer);
size_t IOSurfaceGetWidthOfPlane(IOSurfaceRef buffer, size_t planeIndex);
size_t IOSurfaceGetHeightOfPlane(IOSurfaceRef buffer, size_t planeIndex);
size_t IOSurfaceGetBytesPerElementOfPlane(IOSurfaceRef buffer, size_t planeIndex);
size_t IOSurfaceGetBytesPerRowOfPlane(IOSurfaceRef buffer, size_t planeIndex);
void *IOSurfaceGetBaseAddressOfPlane(IOSurfaceRef buffer, size_t planeIndex);
size_t IOSurfaceGetElementWidthOfPlane(IOSurfaceRef buffer, size_t planeIndex);
size_t IOSurfaceGetElementHeightOfPlane(IOSurfaceRef buffer, size_t planeIndex);
void IOSurfaceSetValue(IOSurfaceRef buffer, CFStringRef key, CFTypeRef value);
CFTypeRef IOSurfaceCopyValue(IOSurfaceRef buffer, CFStringRef key);
void IOSurfaceRemoveValue(IOSurfaceRef buffer, CFStringRef key);
mach_port_t IOSurfaceCreateMachPort(IOSurfaceRef buffer);
IOSurfaceRef IOSurfaceLookupFromMachPort(mach_port_t port);
size_t	IOSurfaceGetPropertyMaximum(CFStringRef property);
size_t	IOSurfaceGetPropertyAlignment(CFStringRef property);
size_t	IOSurfaceAlignProperty(CFStringRef property, size_t value);