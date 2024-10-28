#include <stdint.h>
#include <stdio.h>

#define SIGN_BIT_16 0x8000

uint32_t sign_extend_16bit(uint16_t val);

int main(void) {
    uint16_t immediate = 0xFFFF; // -1 via twos complement
    uint32_t value = 0;
    printf("%d\n", value + immediate); // bad
    printf("%d\n", value + sign_extend_16bit(immediate)); // good
    printf("%d\n", value + (int16_t) immediate); // also good
}

uint32_t sign_extend_16bit(uint16_t val) {
    uint32_t result = val;

    if (val & SIGN_BIT_16) {
        return result | 0xFFFF0000;
    } else {
        return result;
    }
}


