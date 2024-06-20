// This program prints out a danish flag, by
// looping through the rows and columns of the flag.
// Each element inside the flag is a single character.
// (i.e., 1 byte).
//
// (Dette program udskriver et dansk flag, ved at
// sløjfe gennem rækker og kolonner i flaget.)
//

#include <stdio.h>

#define FLAG_ROWS 6
#define FLAG_COLS 12

char flag[FLAG_ROWS][FLAG_COLS] = {
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'}
};

int main(void) {
    // for (int row = 0; row < FLAG_ROWS; row++) {
    //     for (int col = 0; col < FLAG_COLS; col++) {
    //         printf("%c", flag[row][col]);
    //     }
    //     printf("\n");
    // }
    flag_row_init:;
        int row = 0;
    flag_row_cond:
        if (row >= FLAG_ROWS) goto flag_row_end;
    flag_row_body:

    flag_col_init:;
        int col = 0;
    flag_col_cond:
        if (col >= FLAG_COLS) goto flag_col_end;
    flag_col_body:
        printf("%c", flag[row][col]);
    flag_col_step:
        col++;
        goto flag_col_cond;
    flag_col_end:
    printf("\n");
    
    flag_row_step:
        row++;
        goto flag_row_cond;
    flag_row_end:;
}