#include <stdio.h>

int sum(int *arr, int index) {
    if (index == 0) {
        return arr[index];
    } else {
        return arr[index] + sum(arr, index - 1);
    }
}

int main(void) {
    int nums[] = {1, 2, 3, 4, 5};
    printf(sum(nums, 4));
}