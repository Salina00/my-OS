/* kernel.c - Your first C Kernel */

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Hardware text mode color constants. */
enum vga_color {
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_YELLOW = 14,
	VGA_COLOR_WHITE = 15,
};

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 80;

/* direct pointer to video memory */
uint16_t* terminal_buffer = (uint16_t*) 0xB8000; 

/* Function to print a single character to the screen */
void kernel_main(void) 
{
    /* Clear the screen (fill with spaces) */
    for (size_t y = 0; y < VGA_HEIGHT; y++) {
        for (size_t x = 0; x < VGA_WIDTH; x++) {
            const size_t index = y * VGA_WIDTH + x;
            terminal_buffer[index] = (uint16_t) ' ' | (uint16_t) 0x0F00; // 0x07 = Light Grey on Black
        }
    }

    /* Print "Hello World" at the top left */
    const char* str = "Heyy! I am new developer here. My name is Salina I am hoping to build new systems!! wish mee!!";
    size_t i = 0;
    while (str[i] != '\0') {
        /* 0x0F00 means "White Text (F) on Black Background (0)" */
        terminal_buffer[i] = (uint16_t) str[i] | (uint16_t) 0x0F00;
        i++;
    }
}