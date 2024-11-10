// print contents of $HOME/.diary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME ".diary"

int main(int argc, char *argv[]) {
    // Construct pathname
    // $HOME / .diary
    char pathname[256];
    char *home = getenv("HOME");

    snprintf(pathname, 256, "%s/.diary", home);

    FILE *diary_file = fopen(pathname, "r");

    int byte = fgetc(diary_file);
    while (byte != EOF) {
        fputc(byte, stdout);
        byte = fgetc(diary_file);
    }

    fclose(diary_file);

    return 0;
}