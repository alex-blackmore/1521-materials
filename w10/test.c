#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *stream = fopen("test.txt", "r");
    uint32_t result = 0;
    for (int i = 0; i < 4; i++) {
        int byte = fgetc(stream);
        result |= (byte << (i * 8));
    }
    
    uint32_t result2;
    fread(&result2, 4, 1, stream);
}