// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

#include "keymap.h"

// enum my_keycodes {
//   KC_EM = SAFE_RANGE
// };

// const uint16_t PROGMEM combo1[] = {LT(NAVR, KC_ENT), LT(MOUR, KC_TAB), COMBO_END};
// const uint16_t PROGMEM combo2[] = {LT(NSL, KC_SPC), LT(NSSL, KC_BSPC), COMBO_END};
// combo_t key_combos[COMBO_COUNT] = {
//     COMBO(combo1, KC_ESC),
//     COMBO(combo2, LT(FUNL, KC_DEL)), // keycodes with modifiers are possible too!
// }; 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[QWERTY] = LAYOUT(
  KC_Q,          KC_W,          KC_E,              KC_R,              KC_T,                               KC_Y,              KC_U,              KC_I,              KC_O,           KC_P,           
  LCTL_T(KC_A),  LGUI_T(KC_S),  LALT_T(KC_D),      LSFT_T(KC_F), LT(FUNL, KC_G),                     LT(FUNL, KC_H),    LSFT_T(KC_J),      LALT_T(KC_K),      LGUI_T(KC_L),   LCTL_T(KC_QUOTE),
  KC_Z,          ALGR_T(KC_X),  KC_C,              KC_V,              KC_B,                               KC_N,              KC_M,              KC_COMM,           ALGR_T(KC_DOT), KC_SLSH,        
                                              LT(NAVR, KC_ENT),  LT(MOUR, KC_TAB),                   LT(NSL, KC_SPC), LT(NSSL, KC_BSPC)
),

[COLEMAK_DH] = LAYOUT(
  KC_Q,          KC_W,          KC_F,              KC_P,              KC_B,                               KC_J,              KC_L,              KC_U,              KC_Y,           KC_QUOTE,    
  LCTL_T(KC_A),  LGUI_T(KC_R),  LALT_T(KC_S),      LSFT_T(KC_T), LT(FUNL, KC_G),                     LT(FUNL, KC_M),        LSFT_T(KC_N),      LALT_T(KC_E),      LGUI_T(KC_I),   LCTL_T(KC_O),
  KC_Z,          ALGR_T(KC_X),  KC_C,              KC_D,              KC_V,                               KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT), KC_SLSH,     
                                              LT(NAVR, KC_ENT),  LT(MOUR, KC_TAB),                   LT(NSL, KC_SPC), LT(NSSL, KC_BSPC)
),

[NAVR] = LAYOUT(
  KC_LBRC,          KC_7,          KC_8,          KC_9,         KC_RBRC,                KC_AGIN, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE,
  LCTL_T(KC_SCLN),  LGUI_T(KC_4),  LALT_T(KC_5),  LSFT_T(KC_6), KC_EQL,                 KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
  KC_GRV,           KC_1,          KC_2,          KC_3,         KC_BSLS,                KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END, 
                                                  KC_0,         KC_MINS,                KC_ENT,  KC_BSPC
),

[MOUR] = LAYOUT(
  KC_F12,          KC_F7,          KC_F8,          KC_F9,          KC_PSCR,                 KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,  
  LCTL_T(KC_F11),  LGUI_T(KC_F4),  LALT_T(KC_F5),  LSFT_T(KC_F6),  KC_SLCK,                 KC_NU,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, 
  KC_F10,          KC_F1,          KC_F2,          KC_F3,          KC_PAUS,                 KC_NU,   KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
                                                    KC_SPC,         KC_TAB,                 KC_BTN1, KC_BTN3 
),

[MBO] = LAYOUT(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                             KC_TRNS, KC_TRNS,                 KC_BTN1, KC_BTN3
),

[MEDR] = LAYOUT(
  KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                 KC_TOG,  KC_MOD,  KC_HUI,  KC_SAI,  KC_VAI, 
  KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                 KC_NU,   KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                 KC_NU,   KC_NU,   KC_NU,   KC_NU,   KC_NU,  
                             KC_RPRN, KC_UNDS,                 KC_MSTP, KC_MPLY
),

[FUNL] = LAYOUT(
  KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR,                 DF(QWERTY),  DF(COLEMAK_DH),   KC_NA,   KC_NA,   KC_RST, 
  KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SLCK,                 KC_NA,       KC_LSFT,          KC_LCTL, KC_LALT, KC_LGUI,
  KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS,                 KC_NA,       KC_NA,            KC_NA,   KC_TRNS, KC_NA,  
                             KC_ESC,  KC_TAB,                  KC_NA,       KC_NA         
),

[NSL] = LAYOUT(
  KC_LBRC, KC_7,    KC_8,    KC_9,    KC_RBRC,                 KC_NA,   KC_NA,   KC_NA,   KC_NA,      KC_NA,  
  KC_SCLN, KC_4,    KC_5,    KC_6,    KC_EQL,                  KC_NA,   KC_LSFT, KC_LCTL, KC_LALT,    KC_LGUI,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_BSLS,                 KC_NA,   KC_NA,   KC_TRNS,   KC_TRNS,  KC_TRNS,
                             KC_0,    KC_MINS,                 KC_NA,   KC_NA
),

[NSSL] = LAYOUT(
  KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,                 KC_NA,   KC_NA,   KC_NA,   KC_NA,   KC_RST, 
  KC_COLN, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,                 KC_NA,   KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,                 KC_NA,   KC_NA,   KC_NA,   KC_ALGR, KC_NA,  
                             KC_RPRN, KC_UNDS,                 KC_NA,   KC_NA
)};