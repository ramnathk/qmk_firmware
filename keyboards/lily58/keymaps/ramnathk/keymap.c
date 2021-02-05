/* Copyright 2020 Dustin Bosveld <steamyleafjuice@protonmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap.h"
#include "string.h"

#include <stdio.h>

#ifdef AUTO_SHIFT_ENABLE
  #include "process_auto_shift.h"
#endif



enum layers {
    _COLEMAK = 0,
    _HNDALT,
    _QWERT,
    _MEDR,
    _NAVR,
    _MOUR,
    _SYML,
    _NUML,
    _FUNL
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT( \
 //,-----------------------------------------------------.                      ,-----------------------------------------------------.
     mBOSSKY,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MEH,\
 //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
     kCmdSht,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                           KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, KC_HYPR,\
 //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
 kCmdCtrlSft,   GUI_A,   ALT_R,  CTRL_S,  SHFT_T,    KC_G,                           KC_M,  SHFT_N,  CTRL_E,   ALT_I,   GUI_O, _______,\
 //|--------+--------+--------+--------+--------+--------+---------.  ,---------+--------+--------+--------+--------+--------+--------|
     _______,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,  _______,    _______ ,    KC_K,    KC_H, KC_COMM, AGR_DOT, KC_SLSH, _______,\
 //`--------------------------+--------+--------+--------+---------|  |--------+---------+--------+---------+--------------------------'
                               mDblCtrl, MED_ESC, NAV_SPC, KC_TAB,      SYM_ENT,  NUM_BSC,  FN_DEL, NAV_SPC \
                            //`------------------------------------'  `------------------------------------'
    ),

// this is based on the handsdown ALT layout. 
    [_HNDALT] = LAYOUT( \
 //,-----------------------------------------------------.                     ,-----------------------------------------------------.
     _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,\
 //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
     _______,   KC_W ,    KC_G,    KC_H,    KC_M,    KC_K,                          KC_Q,    KC_C,    KC_U,    KC_J, KC_QUOT, _______,\
 //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
     _______,   GUI_R,   ALT_S,  CTRL_N,  SHFT_T,    KC_F,                          KC_Y,  SHFT_A,  CTRL_E,   ALT_O,   GUI_I, _______,\
 //|--------+--------+--------+--------+--------+--------+---------.  ,--------+--------+--------+--------+--------+--------+--------|
     _______,    KC_X,    KC_B,    KC_L,    KC_D,    KC_V,  _______,    _______,    KC_Z,    KC_P, KC_COMM, AGR_DOT,  KC_SLSH, _______,\
 //`--------------------------+--------+--------+--------+---------|  |--------+--------+--------+--------+--------+-----------------'
                                 _______, MED_ESC, NAV_SPC, KC_TAB,    SYM_ENT, NUM_BSC,  FN_DEL, _______ \
                            //`------------------------------------'  `------------------------------------'
    ),

    [_QWERT] = LAYOUT( \
 //,-----------------------------------------------------.                      ,------------------------------------------------------.
     _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,\
 //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+---------+--------|
     _______,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,     KC_P, _______,\
 //|--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+---------+--------|
     _______,   GUI_A,   ALT_S,  CTRL_D,  SHFT_F,    KC_G,                           KC_H,  SHFT_J,  CTRL_K,   ALT_L, GUI_QUOT, _______,\
 //|--------+--------+--------+--------+--------+--------+---------.  ,---------+--------+--------+--------+--------+---------+--------|
     _______,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  _______,    _______,     KC_N,    KC_M, KC_COMM, AGR_DOT,  KC_SLSH, _______,\
 //`--------------------------+--------+--------+--------+---------|  |--------+---------+--------+--------+---------------------------'
                                 _______, MED_ESC, NAV_SPC, KC_TAB,    SYM_ENT, NUM_BSC,  FN_DEL, _______ \
                            //`------------------------------------'  `------------------------------------'
    ),

    [_MEDR] = LAYOUT( \
 //,-----------------------------------------------------.                     ,-----------------------------------------------------.
     _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
     _______,  HNDALT,   QWERT, COLEMAK, KC_ASTG, _______,                       _______, _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------+--------|
     _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                       _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,\
 //|--------+--------+--------+--------+--------+--------+---------.  ,--------+--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,kBootLoad,    _______, _______, _______, _______, _______, _______, _______,\
 //`--------------------------+--------+--------+--------+---------|  |--------+--------+--------+--------+--------+-----------------'
                                _______, _______, _______,  _______,    KC_MSTP, KC_MPLY, KC_MUTE, _______ \
                            //`------------------------------------'  `-----------------------------------'
    ),

    [_NAVR] = LAYOUT( \
 //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, _______, _______, _______, _______,                      KC_AGIN, KC_UNDO,  KC_CUT, KC_COPY, KC_PSTE, _______,\
 //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______,                      KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,\
 //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
     _______, S(KC_ENT), _______, KC_F2, _______, _______, _______,    _______, _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______,\
 //`--------------------------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+-----------------'
                                _______, _______, _______, _______,     KC_ENT, KC_BSPC,  KC_DEL, _______ \
                            //`-----------------------------------'  `-----------------------------------'
    ),


    [_SYML] = LAYOUT( \
 //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                      _______, _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                      _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,\
 //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
     _______, KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, _______,    _______, _______, _______, _______, KC_RALT, _______, _______,\
 //`--------------------------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------------------------'
                                _______, KC_LPRN, KC_RPRN, KC_UNDS,    _______, _______, _______, _______ \
                            //`-----------------------------------'  `-----------------------------------'
    ),

    [_NUML] = LAYOUT( \
 //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                      _______, _______, _______, _______, _______,  _______,\
 //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_SCLN,    KC_4,    KC_5,    KC_6,  KC_EQL,                      _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,\
 //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
     _______, KC_GRV,     KC_1,    KC_2,    KC_3, KC_BSLS, _______,    _______, _______, _______, _______, KC_RALT, _______, _______,\
 //`--------------------------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------------------------'
                                _______,  KC_DOT,    KC_0, KC_MINS,    _______, _______, _______, _______ \
                            //`-----------------------------------'  `-----------------------------------'
    ),

    [_FUNL] = LAYOUT( \
 //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,\
 //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                      _______, _______, _______, _______, _______,  _______,\
 //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK,                      _______, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______,\
 //|--------+--------+--------+--------+--------+--------+--------.  ,--------+--------+--------+--------+--------+--------+--------|
     _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, _______,    _______, _______, _______, _______, KC_RALT, _______, _______,\
 //`--------------------------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------------------------'
                                _______, KC_APP,   KC_SPC,  KC_TAB,    _______, _______, _______, _______ \
                            //`-----------------------------------'  `-----------------------------------'
    ),
};

const char *read_keylog(void);
const char *read_keylogs(void);
bool isBootJump = false;

// 20 fps
#define FRAME_TIMEOUT (1000/20)
// static uint16_t anim_timer = 0;


// Disabling permissive hold for home row asds.
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) { // {{{
    switch (keycode) {
//        case SHFT_T:
//        case SHFT_N:
        case SFT_ENT:
        case CTRL_S:
        case CTRL_E:
        case CTRL_D:        
        case CTRL_K:
        case CTRL_N:
        case ALT_R:
        case ALT_I:
        case ALT_S:
        case ALT_L:
        case ALT_O:
        case AGR_DOT:
        case AGR_COMM:
        case GUI_A:
        case GUI_O:
        case GUI_R:
        case GUI_I:
        case GUI_QUOT:
            // This actually *disables* the permissive hold for these keys.
            // See issue https://github.com/qmk/qmk_firmware/issues/8999
            return true;
        default:
            return false;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
// only the NUM_BSC mod key allows for tapping force hold 
        case NUM_BSC:
            return false;
        default:
            return true;
    }
}

#ifdef OLED_DRIVER_ENABLE

const char *read_logo(void);

// WPM-responsive animation stuff here
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}




#define IDLE_FRAMES 5
#define IDLE_SPEED 20
#define TAP_FRAMES 2
#define TAP_SPEED 20
#define ANIM_FRAME_DURATION 200
#define ANIM_SIZE 512

uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;
uint8_t current_idle_frame = 0;
uint8_t current_tap_frame = 0;
char wpm_str[6];



static void render_status(void) {
    oled_write_P(PSTR("\n"), false);
#ifdef AUTO_SHIFT_ENABLE
    // Auto shift state
    switch (get_autoshift_state()) {
        case true:
        oled_write_P(PSTR(" Auto SH\n"), false);
        break;
        default:
        oled_write_P(PSTR("NO AUTO SH\n"), false);
    }
#else
    oled_write_P(PSTR("NOTO SH\n"), false);
#endif
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _HNDALT:
        case _COLEMAK:
        case _QWERT:
            switch (get_highest_layer(default_layer_state)) {
              case _COLEMAK:
                oled_write_P(PSTR("Colemak DHm"), false);
              break;
              case _QWERT:
                 oled_write_P(PSTR("Qwerty"), false);
               break;
               default:
               oled_write_P(PSTR("Handsdown Alt"), false);
        }
        break;
        case _MEDR:
            oled_write_P(PSTR("Media\n"), false);
        break;
        case _NAVR:
            oled_write_P(PSTR("Navigation\n"), false);
        break;
        case _SYML:
            oled_write_P(PSTR("Symbol\n"), false);
        break;
        case _NUML:
            oled_write_P(PSTR("Number\n"), false);
        break;
        case _FUNL:
            oled_write_P(PSTR("Fn\n"), false);
        break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }

    // Host Keyboard LED Status
    uint8_t led_usb_state = host_keyboard_leds();
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
    oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

void oled_task_user(void) {
    // the below snippet is because of a bug reported that oled_task_user is called too often
    // refer: https://github.com/qmk/qmk_firmware/issues/9375
    if (timer_elapsed(anim_timer) > FRAME_TIMEOUT) {
        anim_timer = timer_read();

        if(isBootJump) {
            oled_clear();
            oled_write_P(PSTR("\nBootloader Jump\n"), false);
            return;
        }
        if (is_keyboard_master()) {
            render_status();
        } else {
            oled_write(read_logo(), false);
        }
    }
}


#endif // for OLED Driver Enable

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case mBOSSKY: // maps to a workflow in alfred
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI(SS_LSFT(SS_LALT(SS_LCTL("1")))));
        }
        break;

        case mDblCtrl:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            //SEND_STRING("QMK is the best thing ever!");
            SEND_STRING(SS_TAP(X_LCTL) SS_TAP(X_LCTL));
        }
        break;

        case kBootLoad:
        if (record->event.pressed) {
            isBootJump = true;
            bootloader_jump();
        }
        break;
    }
    return true;
};
