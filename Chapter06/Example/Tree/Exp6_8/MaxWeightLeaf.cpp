#include "MaxWeightLeaf.h"

#define MAXV (10000 + 10)

int g_left[MAXV];
int g_right[MAXV];

int buildTree(int* inOrder, int inOrderSize, int* postOrder, int postOrderSize)
{
    if (inOrderSize != postOrderSize || inOrderSize == 0) {
        return 0;
    }

    int root = postOrder[postOrderSize - 1];

    int i = 0;
    for ( ; i < inOrderSize; i++) {
        if (inOrder[i] == root) {
            break;
        }
    }

    int leftSize = i;
    int rightSize = inOrderSize - i - 1;

    g_left[root] = buildTree(inOrder, leftSize, postOrder, leftSize);
    g_right[root] = buildTree(inOrder + leftSize + 1, rightSize, postOrder + leftSize, rightSize);
}

void getMaxLeaf(int root, int currSum, int *maxLeaf)
{

}

int MaxWeightLeaf(int* inOrder, int inOrderSize, int* postOrder, int postOrderSize)
{

}