################################################################################
#
# nst led
#
################################################################################
NST_LED_VERSION = 1.0
NST_LED_SITE = /home/wangmm/workspace/amlogic-a113/test_package/nst_led
#NST_LED_SOURCE = nst_led-$(NST_LED_VERSION).tar.gz
#NST_LED_SITE_METHOD = file
NST_LED_SITE_METHOD = local
NST_LED_INSTALL_STAGING = YES
 
define NST_LED_BUILD_CMDS
	$(MAKE) CC=$(TARGET_CXX) -C $(@D) all
endef

define NST_LED_INSTALL_TARGET_CMDS
	$(INSTALL) -D -m 0755 $(@D)/nst_led $(TARGET_DIR)/usr/bin/nst_led
	$(INSTALL) -D -m 0755 package/nst_led/S90nst_led.sh $(TARGET_DIR)/etc/init.d/S90nst_led.sh
endef

define NST_LED_INSTALL_CLEAN_CMDS
	$(MAKE) CC=$(TARGET_CXX) -C $(@D) clean
endef

$(eval $(generic-package)) 