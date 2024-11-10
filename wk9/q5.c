// read 32-byte hexadecimal numbers from a file
// and print low (least significant) byte
// as a signed decimal number (-128..127)

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "require 2 args please\n");
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    // read a number
    uint32_t val;
    while (fscanf(fp, " %x ", &val) != EOF) {
        // get lsb
        uint8_t lsb = val & 0xFF;
        printf("%d\n", lsb);
    }
    fclose(fp);
    return 0;
}
