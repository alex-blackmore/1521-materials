// Print every third number from 24 to 42.
#include <stdio.h>

int main(void) {
    // This 'for' loop is effectively equivalent to a while loop.
    // i.e. it is a while loop with a counter built in.
    // for (int x = 24; x < 42; x += 3) {
    //     printf("%d\n", x);
    // }

third_init:;
    int x = 24;
third_cond:
    if (x >= 42) goto third_end;
third_body:
    printf("%d\n", x);
third_step:
    x += 3;
    goto third_cond;
third_end:
    return 0;
}