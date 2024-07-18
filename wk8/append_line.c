#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr,  "Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    FILE *apple = fopen(argv[1], "r+");
    fseek(apple, 12, SEEK_SET);
    fwrite("hello", 1, 5, apple);
    fclose(apple);
    return 0;
}