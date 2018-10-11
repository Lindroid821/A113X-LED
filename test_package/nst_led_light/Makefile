TARGET=nst_led_light
SRC_FILES=nst_led_light.c
CFLAGS=-Wall -Wextra -Wfatal-errors
LDFLAGS=-L$(TARGET_DIR)/usr/lib -lnst_led
NST_LIBDIR=./nst_lib

all:
	cd $(NST_LIBDIR);$(MAKE);$(MAKE) install
	$(CC) $(SRC_FILES) $(CFLAGS) $(LDFLAGS) -lpthread -lrt -o $(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET_DIR)/usr/bin/$(TARGET)
install:
	install -m 0755 $(TARGET) $(TARGET_DIR)/usr/bin
uninstall:
	rm -f $(TARGET_DIR)/usr/bin/$(TARGET)
