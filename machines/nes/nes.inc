; NES register defines
; based on the nes.inc file supplied with the CC65 compiler suite as well as
; https://nesdev.org/wiki/PPU_registers and https://nesdev.org/wiki/APU_registers

; PPU defines

PPU_CTRL            = $2000
PPU_MASK            = $2001
PPU_STATUS          = $2002
PPU_SPR_ADDR        = $2003
PPU_SPR_IO          = $2004
PPU_SCROLL          = $2005
PPU_ADDR            = $2006
PPU_DATA            = $2007

; APU defines

; Pulse 1 channel
APU_PULSE1CTRL      = $4000
APU_PULSE1RAMP      = $4001
APU_PULSE1FTUNE     = $4002
APU_PULSE1CTUNE     = $4003

; Pulse 2 channel
APU_PULSE2CTRL      = $4004
APU_PULSE2RAMP      = $4005
APU_PULSE2FTUNE     = $4006
APU_PULSE2CTUNE     = $4007

; Triangle channel
APU_TRICTRL1        = $4008
;                   = $4009 (unused)
APU_TRIFREQ1        = $400A
APU_TRIFREQ2        = $400B

; Noise channel
APU_NOISECTRL       = $400C
;                   = $400D (unused)
APU_NOISEFREQ1      = $400E
APU_NOISEFREQ2      = $400F

; DMC channel
APU_MODCTRL         = $4010
APU_MODDA           = $4011
APU_MODADDR         = $4012
APU_MODLEN          = $4013
APU_SPR_DMA         = $4014
APU_CHANCTRL        = $4015

; joypad registers
APU_PAD1            = $4016
APU_PAD2            = $4017
