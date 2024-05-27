#include <stdio.h>

int main(void) {
    printf("The size of a pointer is %lu bytes\n", sizeof(char*));
    printf("The size of an int is %lu bytes\n", sizeof(int));
    printf("The size of a char is %lu bytes\n", sizeof(char));
}