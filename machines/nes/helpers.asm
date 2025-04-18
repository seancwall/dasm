; Helper subroutines

ClearRAM subroutine
        lda #0
        tax
.clearRAM
        sta $00,X
        cpx #$FE
        bcs .skipStack
        sta $100,x
.skipStack
        sta $200,x
        sta $300,x
        sta $400,x
        sta $500,x
        sta $600,x
        sta $700,x
        inx
        bne .clearRAM
        rts

ClearVRAM subroutine
        lda #0
        ldx #0
        ldy #$20
        sty PPU_ADDR
        sta PPU_ADDR
        ldy #$10

.loop   sta PPU_DATA
        inx
        bne .loop
        dey
        bne .loop
        rts

WaitSync subroutine
        bit PPU_STATUS
        bpl WaitSync
        rts

NextRandom subroutine
        lsr
        bcc .NoEor
        eor #$D4
.NoEor  rts

PrevRandom subroutine
        asl
        bcc .NoEor
        eor #$A9
.NoEor  rts

ReadJoypad0 subroutine
        ldy #0
ReadJoypadY
        lda #$01
        sta JOYPAD1,y
        lsr
        sta JOYPAD1,y
        ldx #8
.loop   pha
        lda JOYPAD1,y
        lsr
        pla
        rol
        dex
        bne .loop
        rts
