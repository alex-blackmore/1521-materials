#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "must have at least one argument\n");
        exit(1);
    }
    char *pathname = argv[1];
    FILE *fp = fopen(pathname, "a");
    if (fp == NULL) {
        perror(pathname);
        exit(1);
    }

    int byte = fgetc(stdin);
    while (byte != '\n' && byte != EOF) {
        fputc(byte, fp);
        byte = fgetc(stdin);
    }

    fputc('\n', fp);

    fclose(fp);

    return 0;
}