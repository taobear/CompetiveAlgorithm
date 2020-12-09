#include "MinWeightLeaf.h"

#include <stdio.h>

void test1()
{
    int inOrder[] = {3, 2, 1, 4, 5, 7, 6};
    int postOrder[] = {3, 1, 2, 5, 6, 7, 4};
    
    int inOrderSize = sizeof(inOrder) / sizeof(*inOrder);
    int postOrderSize = sizeof(postOrder) / sizeof(*postOrder);

    printf("test1(): %d\n", MinWeightLeaf(inOrder, inOrderSize, postOrder, postOrderSize));
}

void test2()
{
    int inOrder[] = {7, 8, 11, 3, 5, 16, 12, 18};
    int postOrder[] = {8, 3, 11, 7, 16, 18, 12, 5};

    int inOrderSize = sizeof(inOrder) / sizeof(*inOrder);
    int postOrderSize = sizeof(postOrder) / sizeof(*postOrder);

    printf("test2(): %d\n", MinWeightLeaf(inOrder, inOrderSize, postOrder, postOrderSize));
}

void test3()
{
    int inOrder[] = {255};
    int postOrder[] = {255};

    int inOrderSize = sizeof(inOrder) / sizeof(*inOrder);
    int postOrderSize = sizeof(postOrder) / sizeof(*postOrder);

    printf("test3(): %d\n", MinWeightLeaf(inOrder, inOrderSize, postOrder, postOrderSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}