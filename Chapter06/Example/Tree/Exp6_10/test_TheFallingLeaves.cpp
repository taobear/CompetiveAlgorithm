#include "TheFallingLeaves.h"

#include <stdio.h>
#include <stdlib.h>

void print_1d_nums(int * nums, int numsSize)
{
    if (numsSize == 0) {
        printf("[]\n");
        return;
    }

    printf("[");
    for (int i = 0; i < numsSize - 1; i++) {
        printf("%d, ", nums[i]);
    }

    printf("%d]\n", nums[numsSize - 1]);
}

void test1()
{
    int preOrder[] = { 5, 7, -1, 6, -1, -1, 3, -1, -1 };
    int preOrderSize = sizeof(preOrder) / sizeof(*preOrder);

    int leavesSize = 0;
    int* leaves = TheFallingLeaves(preOrder, preOrderSize, &leavesSize);

    print_1d_nums(leaves, leavesSize);

    free(leaves);
}

void test2()
{
    int preOrder[] = { 8, 2, 9, -1, -1, 6, 5, -1, -1, 12, -1, -1, 3, 7, -1, -1, -1 };
    int preOrderSize = sizeof(preOrder) / sizeof(*preOrder);

    int leavesSize = 0;
    int* leaves = TheFallingLeaves(preOrder, preOrderSize, &leavesSize);

    print_1d_nums(leaves, leavesSize);

    free(leaves);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}