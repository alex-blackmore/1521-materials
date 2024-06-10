// Print every third number from 24 to 42.
#include <stdio.h>

int main(void) {
    // This 'for' loop is effectively equivalent to a while loop.
    // i.e. it is a while loop with a counter built in.
    // for (int x = 24; x < 42; x += 3) {
    //     printf("%d\n", x);
    // }
    // int x = 24;
    // while (x < 42) {
    //     printf("%d\n", x);
    //     x += 3;
    // }
third_num_init:;
    int x = 24;
third_num_cond:
    if (x >= 42) goto third_num_end;
third_num_body:
    printf("%d\n", x);
third_num_step:
    x += 3;
    goto third_num_cond;
third_num_end:
    return 0;
}