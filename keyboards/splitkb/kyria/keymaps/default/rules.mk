OLED_ENABLE = yes
OLED_DRIVER = SSD1306   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow


ifeq ($(strip $(ENCODER_ENABLE)), yes)
	SRC += encoder_utils.c
endif


ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += oled_utils.c
endif


