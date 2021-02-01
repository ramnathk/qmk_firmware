/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#pragma once

// Add retro shift and auto shift
#ifdef AUTO_SHIFT_ENABLE
  #define RETRO_SHIFT 500
  #define AUTO_SHIFT_TIMEOUT 200
  #define NO_AUTO_SHIFT_NUMERIC
  #define NO_AUTO_SHIFT_ALPHA
#endif

// Fix problems with fast typing and homerow mods
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD_PER_KEY
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_FORCE_HOLD_PER_KEY

// Recommended for heavy chording.
// #define QMK_KEYS_PER_SCAN 4


// Disable unnecessary features
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT