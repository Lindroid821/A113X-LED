################################################################################
#
# nst led
#
################################################################################
NST_LED_LIGHT_VERSION = 1.0
NST_LED_LIGHT_SITE = /home/wangmm/workspace/amlogic-a113/test_package/nst_led_light
NST_LED_LIGHT_SITE_METHOD = local
NST_LED_LIGHT_INSTALL_STAGING = YES
 
define NST_LED_LIGHT_BUILD_CMDS
	$(TARGET_CONFIGURE_OPTS) $(MAKE) -C $(@D) all
endef

define NST_LED_LIGHT_INSTALL_TARGET_CMDS
        $(INSTALL) -D -m 0644 $(@D)/nst_lib/libnst_led.so $(TARGET_DIR)/usr/lib/libnst_led.so
	$(INSTALL) -D -m 0755 $(@D)/nst_led_light $(TARGET_DIR)/usr/bin/nst_led_light
endef

define NST_LED_LIGHT_INSTALL_CLEAN_CMDS
	$(TARGET_CONFIGURE_OPTS) $(MAKE) -C $(@D) clean
endef

$(eval $(generic-package)) 
