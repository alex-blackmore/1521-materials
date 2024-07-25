// print contents of $HOME/.diary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME ".diary"

int main(int argc, char *argv[]) {
    char *home_pathname = getenv("HOME");
    // Construct pathname
    // $HOME / .diary
    char pathname[1024];
    snprintf(pathname, 1024, "%s/%s", home_pathname, FILENAME);
    FILE *diary = fopen(pathname , "r");
    if (diary == NULL) {
        perror("fopen");
    }
    int c;
    while ((c = fgetc(diary)) != EOF) {
        putchar(c);
    }
    fclose(diary);
    return 0;
}