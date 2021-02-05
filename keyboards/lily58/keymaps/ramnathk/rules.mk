
BOOTLOADER = atmel-dfu

ENCODER_ENABLE = no       # ENables the use of one or more encoders
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = no      # Audio control and System control
WPM_ENABLE = no           # Allows the keyboard to display wpm

OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
BOOTMAGIC_ENABLE = lite    # Bootmagic lite (only reset)
AUTO_SHIFT_ENABLE = yes

EXTRAFLAGS += -flto


SRC +=  ./lib/logo_reader.c