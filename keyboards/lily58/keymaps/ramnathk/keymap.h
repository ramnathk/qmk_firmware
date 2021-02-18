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

/* Add definitions for MT and LT */
#define SHFT_T MT(MOD_LSFT, KC_T)
#define SHFT_N MT(MOD_RSFT, KC_N)
#define SHFT_F MT(MOD_RSFT, KC_F)
#define SHFT_J MT(MOD_RSFT, KC_J)
#define SHFT_A MT(MOD_RSFT, KC_A) // HNDALT

#define SFT_ENT MT(MOD_LSFT, KC_ENT)

#define CTRL_S MT(MOD_LCTL, KC_S)
#define CTRL_D MT(MOD_LCTL, KC_D)
#define CTRL_E MT(MOD_LCTL, KC_E) // HNDALT
#define CTRL_K MT(MOD_LCTL, KC_K)
#define CTRL_N MT(MOD_LCTL, KC_N)

#define ALT_R MT(MOD_LALT, KC_R)
#define ALT_S MT(MOD_LALT, KC_S)
#define ALT_I MT(MOD_LALT, KC_I)
#define ALT_L MT(MOD_LALT, KC_L)
#define ALT_O MT(MOD_LALT, KC_O) // HNDALT

#define AGR_DOT MT(MOD_RALT, KC_DOT)

#define GUI_A MT(MOD_LGUI, KC_A)
#define GUI_O MT(MOD_LGUI, KC_O)
#define GUI_R MT(MOD_LGUI, KC_R)
#define GUI_I MT(MOD_LGUI, KC_I)  // HNDALT
#define GUI_QUOT MT(MOD_LGUI, KC_QUOT)


#define NAV_SPC LT(_NAVNUM, KC_SPC)
#define NAV_BSC LT(_NAVNUM, KC_BSPC)
#define MOS_TAB LT(_MOUR, KC_TAB) // currently unused as i removed mouse keys layer called _MOUR
#define SYM_ENT LT(_SYML, KC_ENT)
#define FN_DEL LT(_FUNL, KC_DEL)

#define COLEMAK DF(_COLEMAK)
#define HNDALT DF(_HNDALT)
#define QWERT DF(_QWERT)

#define kCmdSht G(KC_LSFT)
#define kCmdCtrlSft G(S(KC_LCTL))
#define kOptSht A(KC_LSFT)
#define kAGIN SCMD(KC_Z)
#define kUNDO LCMD(KC_Z)
#define kCUT LCMD(KC_X)
#define kCOPY LCMD(KC_C)
#define kPSTE LCMD(KC_V)

enum kSplKeys {
    mBOSSKY = SAFE_RANGE,
    mDblCtrl,
    mBootLoad,
};
