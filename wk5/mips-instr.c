#include <stdio.h>
#include <stdint.h>

int main(void) {
    // ADD Rd, Rs, Rt ==== 000000ssssstttttddddd00000100000
    uint32_t add_instruction = 0b0000000101111110101000000100000;
    // Mask for reading the "s" bits
    uint32_t rs_mask = 0b0000011111000000000000000000000;
    // Use & to read only the bits for Rs
    uint32_t result = add_instruction & rs_mask;
    // Move those bits to the right of the number to sanely compare the value
    result = result >> 21;
    // Was it register 5?
    if (result == 5) {
        printf("Register 5!\n");
    } else {
        // Crash the program for fun
        int x = *((int*)0);
    }
}

