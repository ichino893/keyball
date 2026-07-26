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
const uint16_t PROGMEM my_ent[]    = {KC_L, KC_MINS, COMBO_END};  // L + - (追加)
const uint16_t PROGMEM my_tab[]    = {KC_R, KC_T, COMBO_END};     // R + T (変更)

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
    COMBO(my_ent, KC_ENT),       // L + -          -> Enter (変更)
    COMBO(my_tab, KC_TAB),       // R + T          -> Tab   (変更)
};
#endif
