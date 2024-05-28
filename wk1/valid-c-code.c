#include <stdio.h>

int main(void) {
    long long pointer = 1337;
    // Tell C that it's actually a pointer (to the address 1337) using type casting
    int *trust_me = (int*) pointer;
    // Dereference it and pray
    printf("%d\n", *trust_me);
    // Segmentation fault :(
}