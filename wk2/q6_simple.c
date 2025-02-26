#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

medium_cond1:;
    int z;
    if (x > 100) goto medium_cond2;
    goto medium_else;
medium_cond2:
    if (x < 1000) goto medium_body;
    goto medium_else;
medium_body:
    printf("medium\n");
    goto medium_end;
medium_else:
    printf("small/big\n");
medium_end:;
}