/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 * Copyright 2020-2021 Fredrik Salomonsson <plattfot@gmail.com>
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

// #ifdef OLED_ENABLE
//   #define OLED_DISPLAY_128X64
// #endif

#ifdef RGBLIGHT_ENABLE
// #define RGBLIGHT_EFFECT_BREATHING
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
// #define RGBLIGHT_EFFECT_CHRISTMAS
// #define RGBLIGHT_EFFECT_STATIC_GRADIENT
// #define RGBLIGHT_EFFECT_RGB_TEST
// #define RGBLIGHT_EFFECT_ALTERNATING
// #define RGBLIGHT_EFFECT_TWINKLE
  // #define RGBLIGHT_HUE_STEP 8
  // #define RGBLIGHT_SAT_STEP 8
  // #define RGBLIGHT_VAL_STEP 8
#endif

// #define ENCODER_DEFAULT_POS 0x3
// Fixing the skipping with the EC11K encoder
// Currently not working proberly. Need to find the right resolution for the encoder i've choosen.
// #define ENCODER_RESOLUTION 1 

// #define EE_HANDS

// The Leader key allows to flexibly assign macros to key sequences.
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 250

// Fix to avoid missing inputs when changeing directions. 
#define ENCODER_DEFAULT_POS 0x3
// Remove the delay for the OSL keys. Not using any other tap keys.
// Otherwise TAPPING_TERM_PER_KEY would be the way to go.
// #define TAPPING_TERM 0

// Default is 200. Reducing Mod-Tap time before tap becomes hold. Main reason it to support faster typing since I'm using a MT key for switching layer. 
#define TAPPING_TERM 100
#define TAPPING_TERM_PER_KEY
