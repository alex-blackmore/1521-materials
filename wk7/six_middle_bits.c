#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: ./six_middle_bits [value]");
        exit(1);
    }
    printf("%d\n", six_middle_bits(atoi(argv[1])));
}

uint32_t six_middle_bits(uint32_t num) {
    // 0b00000000 00000111 11100000 00000000
    uint32_t mask = 0b00000000000001111110000000000000;
    uint32_t result = num & mask;
    return result >> 13;
}