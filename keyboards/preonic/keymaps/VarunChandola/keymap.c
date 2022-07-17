/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"
#include "print.h"
#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY] = LAYOUT_preonic_grid(
  KC_Q,          KC_W,          KC_E,              KC_R,              KC_T,              KC_NP,             KC_NP,              KC_Y,              KC_U,              KC_I,              KC_O,           KC_P,   
  LCTL_T(KC_A),  LGUI_T(KC_S),  LALT_T(KC_D),      LSFT_T(KC_F),      KC_G,              KC_NP,             KC_NP,              KC_H,              LSFT_T(KC_J),      LALT_T(KC_K),      LGUI_T(KC_L),   LCTL_T(KC_QUOTE),
  KC_Z,          ALGR_T(KC_X),  KC_C,              KC_V,              KC_B,              KC_NP,             KC_NP,              KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT), KC_SLSH,
  DF(QWERTY),   DF(COLEMAK_DH), KC_NP,             KC_NP,             KC_NP,             KC_NP,             KC_NP,              KC_NP,             KC_NP,             KC_NP,             KC_NP,          KC_RST,
  KC_NP,         KC_NP,         KC_NP,             LT(MEDR, KC_ESC),  LT(NAVR, KC_ENT),  LT(MOUR, KC_TAB),  LT(NSL, KC_SPC),    LT(NSSL, KC_BSPC), LT(FUNL, KC_DEL),  KC_NP,             KC_NP,          KC_NP
),

[COLEMAK_DH] = LAYOUT_preonic_grid(
  KC_Q,          KC_W,          KC_F,              KC_P,              KC_B,              KC_NP,             KC_NP,              KC_J,              KC_L,              KC_U,              KC_Y,           KC_QUOTE,   
  LCTL_T(KC_A),  LGUI_T(KC_R),  LALT_T(KC_S),      LSFT_T(KC_T),      KC_G,              KC_NP,             KC_NP,              KC_M,              LSFT_T(KC_N),      LALT_T(KC_E),      LGUI_T(KC_I),   LCTL_T(KC_O),
  KC_Z,          ALGR_T(KC_X),  KC_C,              KC_D,              KC_V,              KC_NP,             KC_NP,              KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT), KC_SLSH,
  DF(QWERTY),   DF(COLEMAK_DH), KC_NP,             KC_NP,             KC_NP,             KC_NP,             KC_NP,              KC_NP,             KC_NP,             KC_NP,             KC_NP,          KC_RST,
  KC_NP,         KC_NP,         KC_NP,             LT(MEDR, KC_ESC),  LT(NAVR, KC_ENT),  LT(MOUR, KC_TAB),  LT(NSL, KC_SPC),    LT(NSSL, KC_BSPC), LT(FUNL, KC_DEL),  KC_NP,             KC_NP,          KC_NP
),

[NAVR] = LAYOUT_preonic_grid(
  KC_LBRC,          KC_7,          KC_8,          KC_9,         KC_RBRC, KC_NP,  KC_NP,  KC_AGIN, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE,
  LCTL_T(KC_SCLN),  LGUI_T(KC_4),  LALT_T(KC_5),  LSFT_T(KC_6), KC_EQL,  KC_NP,  KC_NP,  KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
  KC_GRV,           KC_1,          KC_2,          KC_3,         KC_BSLS, KC_NP,  KC_NP,  KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
  KC_NP,            KC_NP,         KC_NP,         KC_NP,        KC_NP,   KC_NP,  KC_NP,  KC_NP,   KC_NP,   KC_NP,   KC_NP,   KC_NP,
  KC_NP,            KC_NP,         KC_NP,         KC_DOT,       KC_0,    KC_MINS,KC_ENT, KC_BSPC, KC_DEL,  KC_NP,   KC_NP,   KC_NP
),

[MOUR] = LAYOUT_preonic_grid(
  KC_F12,          KC_F7,          KC_F8,          KC_F9,          KC_PSCR, KC_NP,  KC_NP,  KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,
  LCTL_T(KC_F11),  LGUI_T(KC_F4),  LALT_T(KC_F5),  LSFT_T(KC_F6),  KC_SLCK, KC_NP,  KC_NP,  KC_NU,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,   
  KC_F10,          KC_F1,          KC_F2,          KC_F3,          KC_PAUS, KC_NP,  KC_NP,  KC_NU,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,   
  KC_NP,           KC_NP,          KC_NP,          KC_NP,          KC_NP,   KC_NP,  KC_NP,  KC_NP,   KC_NP,   KC_NP,   KC_NP,   KC_NP,
  KC_NP,           KC_NP,          KC_NP,          KC_APP,         KC_SPC,  KC_TAB, KC_BTN1,KC_BTN3, KC_BTN2, KC_NP,   KC_NP,   KC_NP
),

[MBO] = LAYOUT_preonic_grid(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NP,  KC_NP,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NP,  KC_NP,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NP,  KC_NP,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_NP,   KC_NP,   KC_NP,   KC_NP,   KC_NP,   KC_NP,  KC_NP,  KC_NP,   KC_NP,   KC_NP,   KC_NP,   KC_NP,
  KC_NP,   KC_NP,   KC_NP,   KC_TRNS, KC_TRNS, KC_TRNS,KC_BTN1,KC_BTN3, KC_BTN2, KC_NP,   KC_NP,   KC_NP
),

[MEDR] = LAYOUT_preonic_grid(
  KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_NP,  KC_NP,  KC_TOG,  KC_MOD,  KC_HUI,  KC_SAI,  KC_VAI,
  KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, KC_NP,  KC_NP,  KC_NU,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_NP,  KC_NP,  KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,
  KC_NP,   KC_NP,   KC_NP,   KC_NP,   KC_NP,   KC_NP,  KC_NP,  KC_NP,   KC_NP,   KC_NP,   KC_NP,   KC_NP,
  KC_NP,   KC_NP,   KC_NP,   KC_GT,   KC_RPRN, KC_UNDS,KC_MSTP,KC_MPLY, KC_MUTE, KC_NP,   KC_NP,   KC_NP
),

[FUNL] = LAYOUT_preonic_grid(
  KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, KC_NP,  KC_NP,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_RST,
  KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK, KC_NP,  KC_NP,  KC_NA,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, KC_NP,  KC_NP,  KC_NA,   KC_NA,   KC_NA,   KC_TRNS, KC_NA,
  KC_NP,   KC_NP,   KC_NP,   KC_NP,   KC_NP,   KC_NP,  KC_NP,  KC_NP,   KC_NP,   KC_NP,   KC_NP,   KC_NP,
  KC_NP,   KC_NP,   KC_NP,   KC_APP,  KC_SPC,  KC_TAB, KC_NA,  KC_NA,   KC_NA,   KC_NP,   KC_NP,   KC_NP
),

[NSL] = LAYOUT_preonic_grid(
  KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC, KC_NP,  KC_NP,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_RST,
  KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,  KC_NP,  KC_NP,  KC_NA,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_NP,  KC_NP,  KC_NA,   KC_NA,   KC_TRNS,   KC_TRNS, KC_TRNS,
  KC_NP,   KC_NP,   KC_NP,   KC_NP,   KC_NP,   KC_NP,  KC_NP,  KC_NP,   KC_NP,   KC_NP,   KC_NP,   KC_NP,
  KC_NP,   KC_NP,   KC_NP,   KC_DOT,  KC_0,    KC_MINS,KC_NA,  KC_NA,   KC_NA,   KC_NP,   KC_NP,   KC_NP
),

[NSSL] = LAYOUT_preonic_grid(
  KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR, KC_NP,  KC_NP,  KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_RST,
  KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS, KC_NP,  KC_NP,  KC_NA,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE, KC_NP,  KC_NP,  KC_NA,   KC_NA,   KC_NA,   KC_ALGR, KC_NA,
  KC_NP,   KC_NP,   KC_NP,   KC_NP,   KC_NP,   KC_NP,  KC_NP,  KC_NP,   KC_NP,   KC_NP,   KC_NP,   KC_NP,
  KC_NP,   KC_NP,   KC_NP,   KC_GT,   KC_RPRN, KC_UNDS,KC_NA,  KC_NA,   KC_NA,   KC_NP,   KC_NP,   KC_NP
)};