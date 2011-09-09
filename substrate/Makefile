export GO_EASY_ON_ME=1
export SDKVERSION=5.0
export FW_DEVICE_IP=apple-tv.local

include theos/makefiles/common.mk

TWEAK_NAME = exposedKickStart
exposedKickStart_FILES = exposedKickStart.xm
exposedKickStart_LDFLAGS = -undefined dynamic_lookup
include $(FW_MAKEDIR)/tweak.mk
