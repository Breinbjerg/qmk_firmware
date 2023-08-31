OLED_ENABLE = yes
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGB_MATRIX_ENABLE = no     # Disable keyboard RGB matrix, as it is enabled by default on rev3
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow


ifeq ($(strip $(ENCODER_ENABLE)), yes)
	SRC += encoder_utils.c
endif


ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += oled_utils.c
endif


