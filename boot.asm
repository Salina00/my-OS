[org 0x7c00]          ; Tell the assembler where this code will be loaded in memory

mov ah, 0x0e          ; INT 10h / AH=0Eh: Teletype output function
mov al, 'H'           ; Move the letter 'H' into the AL register
int 0x10              ; Call the BIOS interrupt to print it
mov al, 'e'
int 0x10
mov al, 'l'
int 0x10
mov al, 'l'
int 0x10
mov al, 'o'
int 0x10

jmp $                 ; Jump to the current address forever (infinite loop)

; Padding and Magic Number
times 510-($-$$) db 0 ; Fill the rest of the sector with zeros
dw 0xaa55             ; The standard PC boot signature (required by BIOS)