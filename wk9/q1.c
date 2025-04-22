// print contents of $HOME/.diary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME ".diary"

int main(int argc, char *argv[]) {
    // Construct pathname
    // $HOME / .diary
    char *home_path = getenv("HOME");
    char buffer[4096];
    snprintf(buffer, 4096, "%s/.diary", home_path);
    FILE *fp = fopen(buffer, "r");
    int byte = fgetc(fp);
    while (byte != EOF) {
        fputc(byte, stdout);
        byte = fgetc(fp);
    }
    fclose(fp);
    return 0;
}