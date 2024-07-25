// read 32-byte hexadecimal numbers from a file
// and print low (least significant) byte
// as a signed decimal number (-128..127)

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./q5 [filename]");
        exit(1);
    }
    char *pathname = argv[1];
    FILE *file = fopen(pathname, "r");
    
    int x;
    while(fscanf(file, "%x", &x) != EOF) {
        int8_t byte = x & 0xFF;
        printf("%d\n", byte);
    }
    fclose(file);
    return 0;
}
