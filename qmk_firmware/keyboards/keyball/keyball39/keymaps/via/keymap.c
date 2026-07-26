/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// トラックボール・スクロール感度の設定（強制上書き）
#undef KEYBALL_CPI_DEFAULT
#define KEYBALL_CPI_DEFAULT 2000     // カーソル速度（大きいほど速い）

#undef KEYBALL_SCROLL_DIVIDER
#define KEYBALL_SCROLL_DIVIDER 8     // スクロール感度（大きいほど緩やか・遅くなる）

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                                   KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                                   KC_H     , KC_J     , KC_K     , KC_L     , KC_MINS  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                                   KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_LCTL  , KC_LGUI  , KC_LALT  ,LSFT_T(KC_LNG2),LT(1,KC_SPC),LT(3,KC_LNG1),KC_BSPC,LT(2,KC_ENT),LSFT_T(KC_LNG2),KC_RALT,KC_RGUI, MO(2)
  ),

  [1] = LAYOUT_universal(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_RBRC  ,                                                   KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   ,
    KC_F5    , KC_EXLM  , S(KC_6)  ,S(KC_INT3), S(KC_8)  ,                                                   S(KC_INT1), KC_BTN1  , KC_PGUP  , KC_BTN2  , KC_SCLN  ,
    S(KC_EQL),S(KC_LBRC),S(KC_7)   , S(KC_2)  ,S(KC_RBRC),                                                   KC_LBRC  , KC_DLR   , KC_PGDN  , KC_BTN3  , KC_F11   ,
    KC_INT1  , KC_EQL   , S(KC_3)  , _______  , _______  , _______  ,      TO(2)    , TO(0)    , _______  , KC_RALT  , KC_RGUI  , KC_F12
  ),

  [2] = LAYOUT_universal(
    KC_TAB   , KC_7     , KC_8     , KC_9     , KC_MINS  ,                                                   KC_NUHS  , _______  , KC_BTN3  , _______  , KC_BSPC  ,
   S(KC_QUOT), KC_4     , KC_5     , KC_6     ,S(KC_SCLN),                                                   S(KC_9)  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_QUOT  ,
    KC_SLSH  , KC_1     , KC_2     , KC_3     ,S(KC_MINS),                                                   S(KC_NUHS), KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  ,
    KC_ESC   , KC_0     , KC_DOT   , KC_DEL   , KC_ENT   , KC_BSPC  ,      _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  ,                                                   _______  , _______  , SSNP_HOR , SSNP_VRT , SSNP_FRE ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , SCRL_DVI ,                                                   _______  , _______  , _______  , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , SCRL_DVD ,                                                   CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE ,
    QK_BOOT  , KBC_RST  , _______  , _______  , _______  , _______  ,      _______  , _______  , _______  , _______  , KBC_RST  , QK_BOOT
  ),
};
// clang-format on

// レイヤー制御：Layer 2 の時だけスクロールモードを有効化
layer_state_t layer_state_set_user(layer_state_t state) {
    bool is_layer_2 = (get_highest_layer(state) == 2);
    keyball_set_scroll_mode(is_layer_2);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif


// combo setting
#ifdef COMBO_ENABLE

// 1. 同時押しするキーの組み（定義）
const uint16_t PROGMEM my_esc[]    = {KC_Q, KC_W, COMBO_END};     // Q + W
const uint16_t PROGMEM my_btn1[]   = {KC_J, KC_I, COMBO_END};     // J + I
const uint16_t PROGMEM my_btn2[]   = {KC_I, KC_O, COMBO_END};     // I + O
const uint16_t PROGMEM my_bspc[]   = {KC_O, KC_P, COMBO_END};     // O + P
const uint16_t PROGMEM my_p_mins[] = {KC_P, KC_MINS, COMBO_END}; // P + (Pの下)

const uint16_t PROGMEM my_left[]   = {KC_J, KC_K, COMBO_END};     // J + K
const uint16_t PROGMEM my_up[]     = {KC_K, KC_I, COMBO_END};     // K + I
const uint16_t PROGMEM my_right[]  = {KC_K, KC_L, COMBO_END};     // K + L
const uint16_t PROGMEM my_down[]   = {KC_K, KC_COMM, COMBO_END};  // K + ,
const uint16_t PROGMEM my_home[]   = {KC_N, KC_M, COMBO_END};     // N + M
const uint16_t PROGMEM my_pgup[]   = {KC_M, KC_COMM, COMBO_END};  // M + ,
const uint16_t PROGMEM my_pgdn[]   = {KC_COMM, KC_DOT, COMBO_END}; // , + .
const uint16_t PROGMEM my_end[]    = {KC_COMM, KC_SLSH, COMBO_END};// , + /

const uint16_t PROGMEM my_sft[]    = {KC_Z, KC_X, COMBO_END};     // Z + X
const uint16_t PROGMEM my_ent[]    = {KC_L, KC_MINS, COMBO_END};  // L + -
const uint16_t PROGMEM my_tab[]    = {KC_R, KC_T, COMBO_END};     // R + T

// 2. 組み合わせと出力するキーの割り当て
combo_t key_combos[] = {
    COMBO(my_esc, KC_ESC),       // Q + W          -> ESC
    COMBO(my_btn1, KC_BTN1),     // J + I          -> マウス左クリック
    COMBO(my_btn2, KC_BTN2),     // I + O          -> マウス右クリック
    COMBO(my_bspc, KC_BSPC),     // O + P          -> BackSpace
    COMBO(my_p_mins, KC_DEL),    // P + (Pの下)  -> Delete

    COMBO(my_left, KC_LEFT),     // J + K          -> ← (左)
    COMBO(my_up, KC_UP),         // K + I          -> ↑ (上)
    COMBO(my_right, KC_RGHT),    // K + L          -> → (右)
    COMBO(my_down, KC_DOWN),     // K + ,          -> ↓ (下)
    COMBO(my_home, KC_HOME),     // N + M          -> HOME
    COMBO(my_pgup, KC_PGUP),     // M + ,          -> PageUp
    COMBO(my_pgdn, KC_PGDN),     // , + .          -> PageDown
    COMBO(my_end, KC_END),       // . + /          -> END
    COMBO(my_sft, KC_LSFT),      // Z + X          -> Shift
    COMBO(my_ent, KC_ENT),       // L + -          -> Enter
    COMBO(my_tab, KC_TAB),       // R + T          -> Tab
};
#endif
