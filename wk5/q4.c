#include <stdio.h>
#include <stdint.h>

void print_bits(uint32_t control) {
    for (int i = 0; i < 32; i++) {
        if (control & (1 << 31)) {
            putchar('1');
        } else {
            putchar('0');
        }
        control <<= 1;
    }
    putchar('\n');
}

uint32_t six_middle_bits(uint32_t input);

int main(void) {
    uint32_t input;
    scanf("%d", &input);
    uint32_t middle = six_middle_bits(input);
    print_bits(middle);
    printf("%d\n", middle);
}

uint32_t six_middle_bits(uint32_t input) {
    uint32_t mask = 0b00000000000001111110000000000000;
    uint32_t result = input & mask;
    return result >> 13;
}