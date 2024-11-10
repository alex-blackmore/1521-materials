#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "must have at least one argument\n");
        exit(1);
    }
    char *pathname = argv[1];
    FILE *fp = fopen(pathname, "r");
    if (fp == NULL) {
        perror(pathname);
        exit(1);
    }

    char buffer[1024] = {0};
    fgets(buffer, 1024, fp);
    printf("%s", buffer);

    fclose(fp);

    return 0;
}