#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "must have at least one argument\n");
        exit(1);
    }

    char *pathname = argv[1];
    FILE *file_pointer = fopen(pathname, "r");
    if (file_pointer == NULL) {
        perror("fopen");
        exit(1);
    }

    int byte = fgetc(file_pointer);
    while (byte != EOF && byte != 10) {
        fputc(byte, stdout);
        byte = fgetc(file_pointer);
    }
    fputc(0xa, stdout);

    fclose(file_pointer);

    return 0;
}