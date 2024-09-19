#include <stdio.h>
#include <stdlib.h>

int main(void) {
    //int pointer = 1337;
    // Tell C that it's actually a pointer (to the address 1337) using type casting
    //int *trust_me = (int*) pointer;
    // Dereference it and pray
    long long addr = (long long) malloc(1);
    printf("%lld\n", addr);

}