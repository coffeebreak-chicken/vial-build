# 必須のMCU情報
BOARD = GENERIC_RP_RP2040

# 有効化する機能
VIA_ENABLE = yes
VIAL_ENABLE = yes

LTO_ENABLE = yes            # 圧縮の最適化
MOUSEKEY_ENABLE = yes       # マウスキー
EXTRAKEY_ENABLE = yes       # メディアキー

CONSOLE_ENABLE = no         # デバッグ用途
COMMAND_ENABLE = no         # デバッグ用途
BOOTMAGIC_ENABLE = no       # 起動時のキー設定機能を無効化
NKRO_ENABLE = no            # バグの温床
AUDIO_ENABLE = no           # MUSIC操作無効化
BACKLIGHT_ENABLE = no       # バックライト無効化
SPACE_CADET_ENABLE = no     # タップ/ホールドもどき
GRAVE_ESC_ENABLE = no       # タップ/ホールドもどき
MAGIC_ENABLE = no           # 特定のキーが入れ替わる(マジで不要)

# 無効化
#TAP_DANCE_ENABLE = no
#COMBO_ENABLE = no
KEY_OVERRIDE_ENABLE = no


# DYNAMIC_KEYMAPの依存関係の明確化 (通常はVialで自動有効化されます)
DYNAMIC_KEYMAP_ENABLE = yes 

# EEPROM設定の参照を解決するため
EEPROM_SETTINGS_ENABLE = yes

#VIALRGB_ENABLE = yes        # RGBライト(複数)有効化
RGBLIGHT_ENABLE = yes       # RGBライト(単一)有効化

