bits 32
section .multiboot
    dd 0x1BADB002              ; Magic number (tells QEMU "I am a kernel")
    dd 0x00                    ; Flags
    dd - (0x1BADB002 + 0x00)   ; Checksum

section .text
global start
extern kernel_main             ; We will jump to your C function

start:
    cli                        ; Disable interrupts (for now)
    mov esp, stack_space       ; Set up the stack pointer
    call kernel_main           ; JUMP TO C CODE!
    hlt                        ; Halt the CPU if C code returns

section .bss
resb 8192                      ; Reserve 8KB for the stack
stack_space: