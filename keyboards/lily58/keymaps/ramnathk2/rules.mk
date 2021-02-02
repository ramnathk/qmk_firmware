
BOOTLOADER = atmel-dfu

OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
ENCODER_ENABLE = no       # ENables the use of one or more encoders
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = no      # Audio control and System control

BOOTMAGIC_ENABLE = lite    # Bootmagic lite (only reset)
WPM_ENABLE = yes           # Allows the keyboard to display wpm
AUTO_SHIFT_ENABLE = yes

EXTRAFLAGS += -flto
LOCAL_GLCDFONT = yes

SRC +=  ./lib/keylogger.c \
    	./lib/logo_reader.c