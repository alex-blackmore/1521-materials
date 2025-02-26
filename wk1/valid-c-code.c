#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int pointer = 1337;
    int *trust_me = (int*) pointer;
    // printf("%d\n", *trust_me);
    long long addr = (long long) malloc(1);
    printf("%lld\n", addr);

}