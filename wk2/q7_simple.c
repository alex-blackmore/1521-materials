// Print every third number from 24 to 42.
#include <stdio.h>

int main(void) {
    // This 'for' loop is effectively equivalent to a while loop.
    // i.e. it is a while loop with a counter built in.
loop_init:
    ;
    int x = 24;
loop_cond:
    if (x >= 42) goto loop_end;
loop_body:
    printf("%d\n", x);
loop_step:
    x += 3;
    goto loop_cond;
loop_end:
    ;
}