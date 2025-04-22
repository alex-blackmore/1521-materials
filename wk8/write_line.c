#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "must have at least one argument\n");
        exit(1);
    }

    char *pathname = argv[1];
    FILE *file_pointer = fopen(pathname, "a");

    int byte = fgetc(stdin);
    while (byte != EOF && byte != '\n') {
        fputc(byte, file_pointer);
        byte = fgetc(stdin);
    }

    // fprintf(file_pointer, "\n");

    return 0;
}