ifndef ARDUINO_DIR
	ARDUINO_DIR=/usr/share/arduino
endif

ifndef ARDUINO_PORT
	ARDUINO_PORT=/dev/ttyACM*
endif

mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
SKETCHBOOK_PATH=$(patsubst %/,%,$(dir $(mkfile_path)))

USER_LIB_PATH=$(SKETCHBOOK_PATH)/libraries
BOARD_TAG=uno

include $(ARDUINO_DIR)/Arduino.mk
