# my-OS
![my-OS Running](screenshots/demo.png)
<br>
<br>
**my-OS** is a custom 32-bit operating system kernel written from scratch in C and Assembly. It boots via a Multiboot-compliant bootloader and runs in Protected Mode.

## 🚀 Features
- **Custom Bootloader Stub:** Written in NASM Assembly to set up the stack and handle Multiboot headers.
- **Kernel in C:** A freestanding C kernel running on bare metal.
- **VGA Video Driver:** Direct memory manipulation of the VGA buffer (0xB8000) to display text and colors.
- **Cross-Compiler:** Built using a custom GCC toolchain for i686-elf.

## 🛠️ Build Dependencies
To build and run this OS, you need the following tools:
* **NASM** (Assembler)
* **GCC Cross-Compiler** (i686-elf-gcc)
* **QEMU** (Emulator for testing)

## ⚡ How to Build & Run

### 1. Compile the Bootloader
```bash
nasm -f elf32 entry.asm -o entry.o