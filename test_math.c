#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t letter = 'A';      // 0x41
    uint8_t color = 0x0F;      // 0x0F (White on Black)
    
    // THE TEST:
    // Shift the color 8 bits left, then OR it with the letter.
    uint16_t result = (uint16_t)color << 8 | (uint16_t)letter;
    
    printf("Expected: 0xF41\n");
    printf("Actual:   0x%X\n", result);
    
    if (result == 0xF41) {
        printf("SUCCESS! You are ready for the Kernel.\n");
    } else {
        printf("FAILED. Check your math.\n");
    }
    
    return 0;
}