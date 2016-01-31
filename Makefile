TARGET := pboot
OBJS := main.o
CFLAGS := -O2 -Wall
BUILD_PRX := 1
EXTRA_TARGETS := EBOOT.PBP
PSP_EBOOT_TITLE := PBOOT.PBP Writer

PSPSDK=$(shell psp-config --pspsdk-path)
include $(PSPSDK)/lib/build.mak
