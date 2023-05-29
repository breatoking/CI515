;---------------
; Assembly Code
;---------------
#define __SFR_OFFSET 0x00
#include "avr/io.h"
;------------------------
.global start
.global led
.global stop
;------------------------
start:
    LDI   R18, 0
    SBI   DDRB, 2             ;set PB2 (D12) as o/p
    SBI   DDRB, 3             ;set PB3 (D12) as o/p
    SBI   DDRB, 4             ;set PB4 (D12) as o/p
    SBI   DDRB, 5             ;SET PD5 (D12) as o/p
    SBI   DDRB, 6             ;SET PD6 (D12) as o/p
    SBI   DDRB, 7             ;set PB7 (D12) as o/p
    RET                       ;return to setup() function
;---------------------------------------------------------------------------
led:
    CPI   R24, 0x00           ;value in R24 passed by caller compared with 0
    SBI   PORTB, 2            ;set D12 to high
    SBI   PORTB, 7            ;set D12 to high
    RCALL myDelay
    CBI   PORTB, 2            ;set D12 to low
    SBI   PORTB, 3            ;set D12 to high
    SBI   PORTB, 6            ;set D12 to high
    RCALL myDelay
    CBI   PORTB, 3            ;set D12 to low
    CBI   PORTB, 7            ;set D12 to low
    CBI   PORTB, 6            ;set D12 to low
    SBI   PORTB, 5            ;set D12 to high
    SBI   PORTB, 4            ;set D12 to high
    RCALL myDelay
    CBI   PORTB, 5            ;set D12 to low
    SBI   PORTB, 6            ;set D12 to high
    SBI   PORTB, 3            ;set D12 to high
    RCALL myDelay
    CBI   PORTB, 6            ;set D12 to low
    CBI   PORTB, 4            ;set D12 to low
    CBI   PORTB, 3            ;set D12 to low
    SBI   PORTB, 2            ;set D12 to high
    SBI   PORTB, 7            ;set D12 to high
    RCALL myDelay
    RET                       ;return to loop() function
;---------------------------------------------------------------------------
stop:
    OUT   PORTB, R18          ;clear port B
    CBI   PORTB, 2            ;set D12 to low
    CBI   PORTB, 3            ;set D12 to low
    CBI   PORTB, 4            ;set D12 to low
    CBI   PORTB, 5            ;set D12 to low
    CBI   PORTB, 6            ;set D12 to low
    CBI   PORTB, 7            ;set D12 to low
    SBI   PORTB, 3            ;set D12 to high
    SBI   PORTB, 6            ;set D12 to high
    RCALL myDelay
    CBI   PORTB, 6            ;set D12 to low
    CBI   PORTB, 3            ;set D12 to low
    SBI   PORTB, 4            ;set D12 to high
    SBI   PORTB, 7            ;set D12 to high
    RCALL myDelay
    SBI   PORTB, 2            ;set D12 to high
    SBI   PORTB, 5            ;set D12 to high
    CBI   PORTB, 2            ;set D12 to low
    CBI   PORTB, 5            ;set D12 to low
    RCALL myDelay
    RET                       ;return to loop() function
;---------------------------------------------------------------------------
.equ  delayVal, 10000         ;initial count value for inner loop
;---------------------------------------------------------------------------
myDelay:
delay_1s:
    push r24              ; Store register 24 value on stack
    push r25              ; Store register 25 value on stack
    push r26              ; Store register 26 value on stack
    push r27              ; Store register 27 value on stack
    ldi  r24,10           ; Load 10 into register 24
delay_100ms:
    ldi  r25,100          ; Load 100 into register 25
delay_1ms:
    ldi  r27,4010 >> 8    ; Load high byte of value 4010 into reg 27
    ldi  r26,4010 & 255   ; Load low byte of value 4010 into reg 26
delay_ms:
    sbiw r26,1            ; Decrement ms count (r27:r26)
    brne delay_ms         ; loop to delay_ms while > 0
    dec  r25              ; Decrement register 25 by 1
    brne delay_1ms        ; loop for 100 us
    dec  r24              ; decrement register 24 by one
    brne delay_100ms      ; loop for 100 us
    pop  r27              ; Restore value r27 from stack
    pop  r26              ; Restore value r26 from stack
    pop  r25              ; Restore value r25 from stack
    pop  r24              ; Restore value r24 from stack
    ret                   ; return from subroutine
outerLoop:
    LDI   R30, lo8(delayVal)  ;low byte of delayVal in R30
    LDI   R31, hi8(delayVal)  ;high byte of delayVal in R31
innerLoop:
    SBIW  R30, 1              ;subtract 1 from 16-bit value in R31, R30
    BRNE  innerLoop           ;jump if countVal not equal to 0
    ;--------------
    SUBI  R20, 1              ;subtract 1 from R20
    BRNE  outerLoop           ;jump if R20 not equal to 0
    RET
;---------------------------------------------------------------------------