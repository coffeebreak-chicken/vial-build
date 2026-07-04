#include QMK_KEYBOARD_H
/*
┌─────────────────────────────┐
│Esc│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ BS│
└─────────────────────────────┘

┌─────────────────────────────┐
│Tab │ A │ S │ D │ F │ G │ H │ J │ K │ L │ Enter │
└─────────────────────────────┘

┌─────────────────────────────┐
│Shift │ Z │ X │ C │ V │ B │ N │ M │ < │ > │Shift│
└─────────────────────────────┘

┌─────────────────────────────┐
│Ctrl│Win│Alt│SPC│ SPC │ SPC │ SPC │MO(1)│Alt│Ctrl│
└─────────────────────────────┘
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,     KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
        KC_TAB,      KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,              KC_ENTER,
        KC_LSFT,      KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,     KC_DOT,        KC_RSFT,
        KC_LCTL,   KC_LGUI,   KC_LALT,   LT(2,KC_SPC),  LT(3,KC_SPC),  LT(4,KC_SPC),  LT(5,KC_SPC),  MO(1),   KC_RALT,  KC_RCTL
    ),
    [1] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC,          KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH,          _______,
        _______, _______, _______,          KC_DEL,  _______, KC_ENTER,         TG(0),   MO(1),  _______,  TG(1)
    ),
    [2] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC,          KC_BSLS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH,          _______,
        _______, _______, _______,          _______, KC_WH_U, KC_WH_R,          _______,MO(1),  _______, _______
    ),
    [3] = LAYOUT(
        KC_GRV,  _______, KC_UP,   _______,  _______, _______, _______, _______, _______, _______, _______,  KC_DEL,
        _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, KC_SCLN, KC_QUOT,          _______,
        _______, _______, _______, _______,  _______, _______, _______, _______, _______,        KC_UP,     _______,
        _______, _______, _______,           KC_PGUP, _______, KC_PGDN,          KC_LEFT,  MO(1),     KC_DOWN,     KC_RIGHT
    ),
    [4] = LAYOUT(
        KC_GRV,  _______, KC_UP,   _______,  _______, _______, _______, _______, _______, _______, _______,  KC_DEL,
        _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______,  _______, _______, _______, _______, _______,        KC_UP,     _______,
        _______, _______, _______,           KC_LNG2, KC_LNG1, _______,          KC_LEFT, MO(1),      KC_DOWN,     KC_RIGHT
    )
};

// レイヤーとCapsLockを考慮したLED制御
// CapsLockが最優先、それ以外の時はレイヤーの色
void update_led_indicator(void) {// Vialの設定に邪魔されないよう、一時的にモードを固定して有効化
    //rgblight_enable_noeeprom();
    //rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);

    // 1. まずはCapsLockの状態を確認
    // レイヤー別の「色分け」インジケーター
    if (host_keyboard_led_state().caps_lock) {
        rgblight_setrgb_at(0, 255, 0, 0); // CapsLock時は「赤」で固定
        return; // ここで終了（レイヤー判定をスキップ）
    }

    // 2. CapsLockがオフなら、レイヤーの状態を確認
    // CapsLock
    switch (get_highest_layer(layer_state)) {
        case 0: // Default: 消灯
            rgblight_setrgb_at(0, 0, 0, 0);
            break;
        case 1: // 黄色
            rgblight_setrgb_at(0, 255, 255, 0);
            break;
        case 2: // 濃い青（水色を廃止し、はっきりした青に）
            rgblight_setrgb_at(255, 0, 0, 0);
            break;
        case 3: // 緑
            rgblight_setrgb_at(0, 0, 255, 0);
            break;
        case 4: // 紫
            rgblight_setrgb_at(255, 128, 0, 0);
            break;
        case 5: // オレンジ（黄色と区別するため赤を混ぜる）
            rgblight_setrgb_at(0, 255, 80, 0);
            break;
        case 6: // 黄緑（ライム）
            rgblight_setrgb_at(0, 128, 255, 0);
            break;
        case 7: // ピンク（白の代わり。非常に目立ちます）
            rgblight_setrgb_at(150, 255, 0, 0);
            break;
        default:
            rgblight_setrgb_at(0, 0, 0, 0);
            break;
    }
}

// LED色を変更する際のトリガー１
// レイヤーが変わったときに実行
layer_state_t layer_state_set_user(layer_state_t state) {
    update_led_indicator();
    return state;
}

// LED色を変更する際のトリガー２
// CapsLockなどのLED状態が変わったときに実行
// CapsLock、NumLock、ScrollLock が ON または OFF になった時に実行される
bool led_update_user(led_t led_state) {
    update_led_indicator();
    return true;
}

void keyboard_post_init_user(void) {
    // 起動時に一度だけ、Vial側の設定に関わらずLEDを有効化し、静的モードにする
    rgblight_enable(); 
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    update_led_indicator();
}