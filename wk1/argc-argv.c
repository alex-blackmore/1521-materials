#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("I gave %d arguments to this program\n", argc);
    int i = 0;
    while (i < argc) {
        printf("Argument %d: %s\n",i ,argv[i]);
        i++;
    }
}