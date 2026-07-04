#pragma once

#define VIAL_KEYBOARD_UID {0x35, 0x5D, 0x47, 0x52, 0xBD, 0x2A, 0x81, 0xE9}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

//データが送られる順番をずらす
#undef WS2812_BYTE_ORDER
#define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_BGR

// RGBLIGHTの光度を一括調整（0〜255）
#define RGBLIGHT_LIMIT_VAL 50