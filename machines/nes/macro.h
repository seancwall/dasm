;
; macros for NES development based heavily on S. Hugg's 8bitworkshop.com
;

; Cartridge file header
NES_MIRR_HORIZ  = 0
NES_MIRR_VERT   = 1
NES_MIRR_QUAD   = 8

; generate standard iNES header
        MAC NES_HEADER
.NES_MAPPER     SET {1} ; mapper number
.NES_PRG_BANKS  SET {2} ; number of 16K PRG banks, change to 2 for NROM256
.NES_CHR_BANKS  SET {3} ; number of 8K CHR banks, 0 = RAM
.NES_MIRRORING  SET {4} ; see values above
        byte    $4E,$45,$53,$1A     ; "NES" plus DOS end of file marker
        byte    .NES_PRG_BANKS
        byte    .NES_CHR_BANKS
        byte    .NES_MIRRORING|(.NES_MAPPER<<4)
        byte    .NES_MAPPER&$F0
        byte    0,0,0,0,0,0,0,0     ; reserved, pad out to 16 bytes total
        ENDM

; generate boilerplate init code
        MAC NES_INIT
        sei             ; disable IRQs
        cld             ; no support for decimal mode
        ldx #$FF        ; initialize SP
        txs
        inx             ; increment X to 0
        stx PPU_MASK    ; disable rendering
        stx DMC_FREQ    ; disable DMC interrupts
        stx PPU_CTRL    ; disable NMI interrupts
        bit PPU_STATUS  ; clear VBlank flag
        bit APU_CHAN_CTRL ; ack DMC IRQ bit 7
        lda #$40
        sta APU_FRAME   ; disable APU Frame IRQ
        lda #$0F
        sta APU_CHAN_CTRL ; disable DMC, enable/init other channels
        ENDM

; macro to set 16-bit PPU address
        MAC PPU_SETADDR
        lda #>{1}       ; upper byte
        sta PPU_ADDR
        lda #<{1}       ; lower byte
        sta PPU_ADDR
        ENDM

; macro to write 8-bit value to PPU memory
        MAC PPU_SETVALUE
        lda #{1}
        sta PPU_DATA
        ENDM

; macro to save A/X/Y registers
        MAC SAVE_REGS
        pha
        txa
        pha
        tya
        pha
        ENDM

; macro to restore A/X/Y registers
        MAC RESTORE_REGS
        pla         ; pop off y and transfer it
        tya
        pla         ; pop off x and transfer it
        tax
        pla         ; pop off a
        ENDM

; macro to sleep given number of cycles
; original author: Thomas Jentzsch
; defining NO_ILLEGAL_OPCODES MAY AFFECT FLAGS (uses bit instruction)

        MAC SLEEP   ; usage: SLEEP n  (n > 1)
.CYCLES SET {1}

        IF .CYCLES < 2
            ECHO "MACRO ERROR: 'SLEEP': Duration must be > 1"
            ERR
        ENDIF

        IF .CYCLES & 1      ; if odd number of cycles
            IFNCONST NO_ILLEGAL_OPCODES
                nop 0
            ELSE
                bit $00
            ENDIF
.CYCLES     SET .CYCLES - 3
        ENDIF

        REPEAT .CYCLES / 2
            nop
        REPEND
        ENDM
