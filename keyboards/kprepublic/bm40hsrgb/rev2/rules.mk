# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = no       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
EXTRAKEY_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
MUSIC_ENABLE = no
RGB_MATRIX_ENABLE = no
RGB_MATRIX_DRIVER = custom
WS2812_DRIVER_REQUIRED = yes

# COMMON_VPATH += $(DRIVER_PATH)/led/issi
SRC += is31fl3733.c
QUANTUM_LIB_SRC += i2c_master.c

LAYOUTS_HAS_RGB = no

LTO_ENABLE = yes
AUTO_SHIFT_ENABLE = yes
DYNAMIC_MACRO_ENABLE = no
MIDI_ENABLE = no

COMBO_ENABLE = yes
VPATH += keyboards/gboards
