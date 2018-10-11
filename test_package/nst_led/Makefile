TARGET=nst_led
PRE=ledClient.c clientTest.c
#CFLAGS=-Wall -Wextra -D_USE_LEDRING_DAEMON
CFLAGS=-Wall -Wextra
INCLUDES=ledClient.h


$(TARGET):$(PRE)
	$(CC) $(CFLAGS) $(LDFLAGS) -lpthread -lrt -o $@ $^

all:$(TARGET)

.PHONY: clean
clean:
	rm -f $(TARGET_DIR)/usr/bin/$(TARGET)
install:
	install -m 0755 $(TARGET) $(TARGET_DIR)/usr/bin/
uninstall:
	rm -f $(TARGET_DIR)/usr/bin/$(TARGET)
