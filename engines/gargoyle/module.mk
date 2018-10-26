MODULE := engines/gargoyle

MODULE_OBJS := \
	conf.o \
	detection.o \
	events.o \
	fonts.o \
	gargoyle.o \
	glk.o \
	picture.o \
	screen.o \
	streams.o \
	string.o \
	windows.o \
	window_mask.o \
	window_graphics.o \
	window_pair.o \
	window_text_buffer.o \
	window_text_grid.o \
	scott/detection.o \
	scott/scott.o

# This module can be built as a plugin
ifeq ($(ENABLE_GARGOYLE), DYNAMIC_PLUGIN)
PLUGIN := 1
endif

# Include common rules
include $(srcdir)/rules.mk