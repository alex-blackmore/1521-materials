#include <stdio.h>

int main(void) {
    // for (int i = 1; i <= 10; i++) {
    //     for (int j = 0; j < i; j++) {
    //         printf("*");
    //     }
    //     printf("\n");
    // }

outer_init:;
    int i = 1;
outer_cond:
    if (i > 10) goto outer_end;
outer_body:;

inner_init:;
    int j = 0;
inner_cond:
    if (j >= i) goto inner_end;
inner_body:
    printf("*");
inner_step:
    j++;
    goto inner_cond;
inner_end:
    printf("\n");
outer_step:
    i++;
    goto outer_cond;
outer_end:

    return 0;
}