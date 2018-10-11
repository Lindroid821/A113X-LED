TARGET=nst_led
SRC_FILES=nst_led.c
CFLAGS=-Wall -Wextra -Wfatal-errors

all:
	$(CC) $(SRC_FILES) $(CFLAGS) -lpthread -lrt -fpic -shared -o lib$(TARGET).so

.PHONY: clean
clean:
	rm -f $(TARGET_DIR)/usr/lib/lib$(TARGET).so
install:
	install -m 0644 lib$(TARGET).so $(TARGET_DIR)/usr/lib
