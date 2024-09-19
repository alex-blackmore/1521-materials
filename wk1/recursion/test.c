#include <stdio.h>

int fac(int n) {
    if (n == 0) {
        return 1;
    }
    return n * fac(n - 1);
}

int main(void) {
    int test = 1000;
    printf("%d\n", fac(test));
}