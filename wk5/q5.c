#include <stdint.h>

// Whether the printer is out of ink
#define NO_INK (0x1)       // 0b 0000 0001
// Whether to print/scan in colour
#define COLOUR (0x2)       // 0b 0000 0010
// Select print mode
#define SELECT_PRINT (0x4) // 0b 0000 0100
// Select scan mode
#define SELECT_SCAN (0x8)  // 0b 0000 1000
// Start print/scan
#define START (0x10)       // 0b 0001 0000

void print_bits(uint8_t control) {
    for (int i = 0; i < 8; i++) {
        if (control & (1 << 7)) {
            putchar('1');
        } else {
            putchar('0');
        }
        control <<= 1;
    }
    putchar('\n');
}

uint8_t check_ink(uint8_t control) {

}

uint8_t replace_ink(uint8_t control) {

}

uint8_t set_colour_and_scan(uint8_t control) {

}

uint8_t toggle_print_scan(uint8_t control) {
    
}

uint8_t check_ready(uint8_t control) {
    // Only one mode is selected

    // If print mode, check there is ink

    // Wait for the control to indicate finished (hint: we are never leaving this loop)
}