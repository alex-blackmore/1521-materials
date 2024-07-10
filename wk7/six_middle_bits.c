#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: ./sxi_middle_bits [value]");
        exit(1);
    }
    printf("%d\n", six_middle_bits(atoi(argv[1])));
}

uint32_t six_middle_bits(uint32_t num) {
    return 0;
}