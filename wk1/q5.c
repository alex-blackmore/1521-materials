#include <stdio.h>

int main(void) {
    int count = 0;
    while (1) {
        int character = getchar();
        if (character == EOF) {
            printf("%d\n", count);
            return 0;
        }
        count++;
    }
}