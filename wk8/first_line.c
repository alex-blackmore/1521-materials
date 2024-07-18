#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr,  "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *fp = fopen(argv[1], "r");
    int c = fgetc(fp);
    while (c != '\n' && c != EOF) {
        fprintf(stdout, "%c", c);
        printf("%c", c);
        putchar(c);
        fputc(c, stdout);
        fputc(c, stderr); // dont do that one
        
        c = fgetc(fp);
    }
    putchar('\n');
    return 0;
}