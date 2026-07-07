#pragma once

// コンソール機能の無効化
#define NO_CONSOLE

// オーディオ機能の無効化します.
#define NO_MUSIC
#define NO_AUDIO_ENABLE

// Vialで利用可能なレイヤー数を8層に制限します.
#define DYNAMIC_KEYMAP_LAYER_COUNT 8

// タップ/ホールドの判定時間(ミリ秒)を設定します. ※デフォルト値は200ms
#define TAPPING_TERM 200

// ホールド判定が、別のキーに中断されることを防ぎます.(PERMISSIVE_HOLDは今回見送り)
#define IGNORE_MOD_TAP_INTERRUP

// 5ms のデバウンス(チャタリング対策)
#define DEBOUNCE 5

// RGB LEDの数
#define RGBLIGHT_LED_COUNT 1

// 他のキーが離された瞬間にHold判定
#define PERMISSIVE_HOLD

// 他のキーが押された瞬間にHold判定
//#define HOLD_ON_OTHER_KEY_PRESS