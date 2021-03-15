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

#define MC_SAVE LCTL(KC_S)
#define MC_SLCT LCTL(KC_A)
#define MC_UNDO LCTL(KC_Z)
#define MC_CUT LCTL(KC_X)
#define MC_COPY LCTL(KC_C)
#define MC_PASTE LCTL(KC_V)
#define MC_FIND LCTL(KC_F)

#define KC_BSPC_WD LALT(KC_BSPC)

enum preonic_layers {
  _BASE,
  _FIRST,
  _SECOND,
  _LEFT,
  _RIGHT,
  _LRCOMBINED
};

enum preonic_keycodes {
  LEFT = SAFE_RANGE,
  RIGHT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |SHF_EN|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |FIRST |LEFT  |THIRD | Spc  |RIGHT | Left |Down  |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,        KC_4,       KC_5,       KC_6,    KC_7,        KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,        KC_R,       KC_T,       KC_Y,    KC_U,        KC_I,    KC_O,    KC_P,    KC_BSPC,
  KC_ESC,  KC_A,    KC_S,    KC_D,        KC_F,       KC_G,       KC_H,    KC_J,        KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,        KC_V,       KC_B,       KC_N,    KC_M,        KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_ENT),
  KC_LCTL, KC_LGUI, KC_LALT, MO(_FIRST),  LEFT,MT(_SECOND,KC_SPC),KC_SPC,  RIGHT,       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* FIRST
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |      |   F  |   P  |   G  |   J  |   L  | MS_U |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |MS_BT1|MS_BT2|MS_WHU|MS_WHD|   D  |   H  | MS_L | MS_D | MS_R |      |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_FIRST] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_MS_U, KC_Y,    KC_SCLN, KC_BSPC_WD,
  KC_ESC, KC_BTN1, KC_BTN2, KC_WH_U, KC_WH_D,  KC_D, _______, KC_MS_L,    KC_MS_D, KC_MS_R, KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* SECOND
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_SECOND] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC_WD,
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT,
  _______, _______, _______, _______, _______, _______, _______, _______,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* LEFT
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |SELECT| SAVE |      | FIND |  F5  |  F6  | Left |  Up  | Down |Right |  |   | 
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | UNDO |  CUT | COPY |PASTE |      |      |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LEFT] = LAYOUT_preonic_grid(
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR,   KC_LPRN, KC_RPRN, KC_BSPC,
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,  KC_ASTR,   KC_LPRN, KC_RPRN, KC_BSPC_WD,
  KC_DEL,  MC_SLCT, MC_SAVE, _______, MC_FIND, _______, KC_LEFT, KC_DOWN,  KC_UP,     KC_RGHT, _______, KC_PIPE,
  _______, MC_UNDO, MC_CUT , MC_COPY,MC_PASTE, _______, _______,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END,  _______,
  _______, _______, _______, _______, _______, _______, _______, _______,  KC_MNXT,   KC_VOLD, KC_VOLU, KC_MPLY
),

/* RIGHT
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   [  |   ]  |   -  |   =  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | Pg Up| Pg Dn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RIGHT] = LAYOUT_preonic_grid(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC_WD,
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,  KC_BSLS,
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* THIRD_FOURTH (THIRD + FOURTH)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset| Debug|      |      |      |      |TermOf|TermOn|      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Home  |Pg Dn |Pg Up | End  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LRCOMBINED] = LAYOUT_preonic_grid(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  CG_TOGG, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,
  _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END , _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     // If console is enabled, it will print the matrix position and status of each key pressed
// #ifdef CONSOLE_ENABLE
//     uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
// #endif 
  switch (keycode) {
        // case BASE:
        //   if (record->event.pressed) {
        //     set_single_persistent_default_layer(_BASE);
        //   }
        //   return false;
        //   break;
        // case FIRST:
        //   if (record->event.pressed) {
        //     set_single_persistent_default_layer(_FIRST);
        //   }
        //   return false;
        //   break;
        // case SECOND:
        //   if (record->event.pressed) {
        //     set_single_persistent_default_layer(_SECOND);
        //   }
        //   return false;
        //   break;
        case LEFT:
          if (record->event.pressed) {
            layer_on(_LEFT);
            update_tri_layer(_LEFT, _RIGHT, _LRCOMBINED);
          } else {
            layer_off(_LEFT);
            update_tri_layer(_LEFT, _RIGHT, _LRCOMBINED);
          }
          return false;
          break;
        case RIGHT:
          if (record->event.pressed) {
            layer_on(_RIGHT);
            update_tri_layer(_LEFT, _RIGHT, _LRCOMBINED);
          } else {
            layer_off(_RIGHT);
            update_tri_layer(_LEFT, _RIGHT, _LRCOMBINED);
          }
          return false;
          break;
        // case BACKLIT:
        //   if (record->event.pressed) {
        //     register_code(KC_RSFT);
        //     #ifdef BACKLIGHT_ENABLE
        //       backlight_step();
        //     #endif
        //     #ifdef __AVR__
        //     writePinLow(E6);
        //     #endif
        //   } else {
        //     unregister_code(KC_RSFT);
        //     #ifdef __AVR__
        //     writePinHigh(E6);
        //     #endif
        //   }
        //   return false;
        //   break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RIGHT)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_LRCOMBINED);
            } else {
                layer_off(_LRCOMBINED);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case LEFT:
    case RIGHT:
      return false;
    default:
      return true;
  }
}