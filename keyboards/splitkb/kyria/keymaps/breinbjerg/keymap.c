/* Copyright 2020-2021 Fredrik Salomonsson <plattfot@gmail.com>
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
#include "version.h"
#include "stdio.h"

// Layers for my keyboard. 
enum layers {
    _DEFAULT,
    _LOWER,
    _RAISE,
    _NAV,
    _ADJUST,
};

// custom keycodes used for macros 
enum custom_keycodes {
    TILE_TOP,
    TILE_DOWN,
    TILE_LEFT,
    TILE_RIGHT,
};


#define MO_ADJT MO(_ADJUST)
#define L_RAISE MO(_RAISE)
#define L_LOWER MO(_LOWER)
#define L_NAV   MO(_NAV)
#define EU_TDOT RSA(KC_SLSH)
#define EU_CDOT RALT(KC_EQUAL)
#define EU_DEG  RALT(KC_SCLN)
#define RSHIFT_ENT  MT(MOD_RSFT, KC_ENT)
#define ALT_SPACE  MT(MOD_LALT, KC_SPACE)
#define LOWER_ENT  LT(L_LOWER,KC_ENT)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Default
 *
 * ,-------------------------------------------.                              ,-----------------------------------------------'
 * |  Esc   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  RCtrl     |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+------------|
 * |  Tab   |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  |   ;  |   '        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | Lead | DEL  |  | RALT |      |   N  |   M  |   ,  |   .  |   /  | RShift/ent |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+--------------------------'
 *                        | MPlay| GUI  | LCtrl| LALT |RAISE |  | Enter|BSpace| NAV  |ADJUST|Scroll|
 *                        |      |      |      | space|      |  |      |      |      |      | Lock |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_DEFAULT] = LAYOUT(
      KC_ESC,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,                                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_RCTL,
      KC_TAB,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,                                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,    QK_LEAD,  KC_DEL, KC_RALT, KC_DEL, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSHIFT_ENT,
                               KC_MPLY,KC_LGUI,KC_LCTL, ALT_SPACE, L_RAISE, LOWER_ENT,  KC_BSPC, L_NAV,   MO_ADJT, KC_SCROLL_LOCK
    ),
    

/*
 * Lower Layer: Left symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  @   |  #   |  $   |  %   |                              |  F6  |  F7  |  F8  |  F9  | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  |   |  _   |  \   |  -   |  +   |                              | F12  |KC_NUM|      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  °   |  :   |  (   |  )   |  ×   |      |ADJUST|  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LOWER] = LAYOUT(
      _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, KC_PIPE, KC_UNDS, KC_BSLS, KC_MINS, KC_PLUS,                                     KC_F12,  KC_NUM, _______, _______, _______, _______,
      _______, EU_DEG,  KC_COLN, KC_LPRN, KC_RPRN, EU_CDOT, _______, MO_ADJT, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Raise Layer: Right symbols + state
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |                              |   ^  |  &   |  *   |  ~   |  ?   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      | F11  |                              |   =  |  {   |  }   |  [   |  ]   |   `    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |ADJUST|      |   …  |  "   |  <   |  >   |  /   |CapsLock|
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | Mute |      |      |      |      |  |      |      |      |      |Insert|
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_CIRC, KC_AMPR, KC_ASTR, KC_TILDE,KC_QUES, _______,
      _______, _______, _______, _______, _______, KC_F11,                                      KC_EQUAL,KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_GRV,
      _______, _______, _______, _______, _______, _______, _______, _______, MO_ADJT, _______, EU_TDOT, KC_DQUO, KC_LT,   KC_GT,   _______, KC_CAPS,
                                 KC_MUTE, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS

    ),
/*
 * Navigation Layer: Number/Function keys, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |  Top |      |      |                              |      |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Left | Down | Right|      |                              |      |  4   |  5   |  6   |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |  1   |  2   |  3   |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */

    [_NAV] = LAYOUT(
      _______, _______,   _______, TILE_TOP ,    _______, _______,                                     _______, KC_7,    KC_8,    KC_9,    KC_0, _______,
      _______, _______, TILE_LEFT, TILE_DOWN, TILE_RIGHT, _______,                                     _______, KC_4,    KC_5,    KC_6, _______, _______,
      _______, _______,   _______,   _______,    _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3, _______, _______,
                                     _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

//  Old layout saved just in case I get annoyed and want to go back again. 
    // [_NAV] = LAYOUT(
    //   _______, KC_1, 	KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    //   _______, _______, _______, _______, _______, _______,                                     _______, KC_LEFT, KC_UP, KC_DOWN,   KC_RGHT, _______,
    //   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    // ),
/*
 * Adjust Layer: RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};
// clang-format on

/* void keyboard_post_init_user(void) { */
/*   rgblight_setrgb(51, 135, 204); */
/* } */

//layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

// clang-format off
/* Kyria logo - use all of the Space on the OLED.*/
// static void render_logo(void) {
//     static const char PROGMEM kyria_logo[] = {
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
//         0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
//         0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
//     };
//     oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
// }
/* Linux Logo*/
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        153,154,10,
        185,186,0
    };

    oled_write_P(qmk_logo, false);
}
/** QMK FIRMWARE LOGO*/
// static void render__logo(void) {
//     static const char PROGMEM qmk_logo[] = {
//         0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
//         0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
//         0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};

//     oled_write_P(qmk_logo, false);
// }
// clang-format on
static void render_static_info(void) {
    render_logo();
    oled_write_P(PSTR("Breinbjerg\n"), false);
}

static void render_status(void) {
    char wpm_str [10];
    // QMK Logo and version information
    render_logo();
    oled_write_P(PSTR("\nBreinbjerg\n"), false);

    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _DEFAULT:
            oled_write_P(PSTR("base\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("<-sym/fun->\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("<-fun/sym->\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("num/nav\n"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("adjust\n"), false);
            break;
        default:
            oled_write_P(PSTR("undefined\n"), false);
    }

    // Host Keyboard LED Status and Double tap
    led_t led_state = host_keyboard_led_state();
    if (led_state.num_lock) {
        oled_write_P(PSTR("NUMLCK "), false);
    } else {
        oled_write_P(PSTR("       "), false);
    }

    if (led_state.caps_lock) {
        oled_write_P(PSTR("CAPLCK "), false);
    } else {
        oled_write_P(PSTR("       "), false);
    }

    oled_write_P(led_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    sprintf(wpm_str, "       WPM: %03d", get_current_wpm());  
    oled_write_P(wpm_str, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_static_info();
    }
    return false;
}
#endif


void leader_end_user(void) {
    // Sway navigation
    if (leader_sequence_one_key(KC_Q)) {  // Jump to workspace 1
        SEND_STRING(SS_LGUI("1"));
    }
    if (leader_sequence_one_key(KC_W)) {  // Jump to workspace 2
        SEND_STRING(SS_LGUI("2"));
    }
    if (leader_sequence_one_key(KC_E)) {  // Jump to workspace 3
        SEND_STRING(SS_LGUI("3"));
    }
    if (leader_sequence_one_key(KC_R)) {  // Jump to workspace 4
        SEND_STRING(SS_LGUI("4"));
    }
    if (leader_sequence_one_key(KC_T)) {  // Jump to workspace 5
        SEND_STRING(SS_LGUI("5"));
    }
}


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_DEFAULT] =   { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    [_LOWER] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(C(KC_Z), C(KC_Y))  },
    [_NAV] = { ENCODER_CCW_CW(KC_UP, KC_DOWN),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [_ADJUST] = { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
};
#endif


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LOWER_ENT:
            return TAPPING_TERM;

        case ALT_SPACE:
            return TAPPING_TERM + 100;

        default:
            return TAPPING_TERM;
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
    case TILE_TOP:
        // Only do if key is pressed
        if (record->event.pressed){
        SEND_STRING(SS_RGUI(SS_LSFT("t"))); 
        }
        break;
    case TILE_DOWN:
        if (record->event.pressed){
        SEND_STRING(SS_RGUI(SS_LSFT("d")));
        }
        break;
    case TILE_RIGHT:
        if (record->event.pressed){
        SEND_STRING(SS_RGUI(SS_LSFT("r")));
        }
        break;
    case TILE_LEFT:
        if (record->event.pressed){
        SEND_STRING(SS_RGUI(SS_LSFT("l")));
        }
        break;
    
    default:
        break;
    }

    return true;
}