#include <stdio.h>
#include <stdlib.h>

int codepoint_length(char byte);

int main(int argc, char **argv) {
    if (argc < 2) {
        exit(1);
    }

    char *utf8_string = argv[1];
    int i = 0;
    int count = 0;

    while(utf8_string[i] != '\0') {
        int this_length = codepoint_length(utf8_string[i]);
        i += this_length;
        count++;
    }

    printf("String has %d utf8 chars\n", count);
}

int codepoint_length(char byte) {
    // byte matching:
    // 0xxxxxxx
    if ((byte & 0b10000000) == 0b00000000) {
        return 1;
    }
    // 110xxxxx
    else if ((byte & 0b11100000) == 0b11000000) {
        return 2;
    }
    // 1110xxxx
    else if ((byte & 0b11110000) == 0b11100000) {
        return 3;
    }
    // 11110xxx
    else if ((byte & 0b11111000) == 0b11110000) {
        return 4;
    }
    // : error
    puts("curse you user");
    return *((int*) 0);
}