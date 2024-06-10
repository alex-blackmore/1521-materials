#include <stdio.h>

int main(void) {
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    // if (x > 100 && x < 1000) {
    //     printf("medium\n");
    // } else {
    //     printf("small/big\n");
    // }
size_x_gt_100:
    if (x > 100) goto size_x_lt_1000;
    goto size_else;
size_x_lt_1000:
    if (x < 1000) goto size_body;
    goto size_else;
size_body:
    printf("medium\n");
    goto size_end;
size_else:
    printf("small/big\n");
size_end:
    return 0;
}