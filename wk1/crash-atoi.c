#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *totally_a_number = "twelve";
    int x = atoi(totally_a_number);
    // this should work right?
    printf("12 = %d\n", x);
    // hmmmm
}