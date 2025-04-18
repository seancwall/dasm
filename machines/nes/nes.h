;
; NES definitions based heavily on S. Hugg's version from 8bitworkshop.com
;

; Register definitions

PPU_CTRL        = $2000
PPU_MASK        = $2001
PPU_STATUS      = $2002
OAM_ADDR        = $2003
OAM_DATA        = $2004
PPU_SCROLL      = $2005
PPU_ADDR        = $2006
PPU_DATA        = $2007

; This is an odd register, as it's part of the APU but it's used for the PPU
PPU_OAM_DMA     = $4014

DMC_FREQ        = $4010
APU_STATUS      = $4015
APU_NOISE_VOL   = $400C
APU_NOISE_FREQ  = $400E
APU_NOISE_TIMER = $400F
APU_DMC_CTRL    = $4010
APU_CHAN_CTRL   = $4015
APU_FRAME       = $4017

JOYPAD1         = $4016
JOYPAD2         = $4017

; OAM local RAM copy from $0200-$02FF
OAM_RAM         = $0200

; PPU_CTRL flags
CTRL_NMI        = %10000000     ; Execute NMI on VBlank
CTRL_8x8        = %00000000     ; Use 8x8 sprites
CTRL_8x16       = %00100000     ; Use 8x16 sprites
CTRL_BG_0000    = %00000000     ; Background Pattern Table at $0000 in VRAM
CTRL_BG_1000    = %00010000     ; Background Pattern Table at $1000 in VRAM
CTRL_SPR_0000   = %00000000     ; Sprite Pattern Table at $0000 in VRAM
CTRL_SPR_1000   = %00001000     ; Sprite Pattern Table at $1000 in VRAM
CTRL_INC_1      = %00000000     ; Increment PPU Address by 1 (horizontal rendering)
CTRL_INC_32     = %00000100     ; Increment PPU Address by 32 (vertical rendering)
CTRL_NT_2000    = %00000000     ; Name Table Address at $2000
CTRL_NT_2400    = %00000001     ; Name Table Address at $2400
CTRL_NT_2800    = %00000010     ; Name Table Address at $2800
CTRL_NT_2C00    = %00000011     ; Name Table Address at $2C00

; PPU_MASK flags
MASK_TINT_RED   = %00100000     ; Red Background
MASK_TINT_BLUE  = %01000000     ; Blue Background
MASK_TINE_GREEN = %10000000     ; Green Background
MASK_SPR        = %00010000     ; Sprites Visible
MASK_BG         = %00001000     ; Background Visible
MASK_SPR_CLIP   = %00000100     ; Sprites clipped on left column
MASK_BG_CLIP    = %00000010     ; Background clipped on left column
MASK_COLOR      = %00000000     ; Display in color
MASK_MONO       = %00000001     ; Display in monochrome

; read flags
F_BLANK         = %10000000     ; VBlank active
F_SPRITE0       = %01000000     ; VBlank hit sprite 0
F_SCAN8         = %00100000     ; More than 8 sprites on current scanline
F_WIGNORE       = %00010000     ; VRAM writes currently ignored
