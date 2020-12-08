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
    return root;
}

void getMaxLeaf(int root, int currSum, int *maxLeaf)
{
    if (root == 0) {
        return;
    }

    currSum += root;
    if (g_left[root] == 0 && g_right[root] == 0) {
        *maxLeaf = currSum > *maxLeaf ? currSum : *maxLeaf;
        return;
    }

    if (g_left[root] != 0) {
        getMaxLeaf(g_left[root], currSum, maxLeaf);
    }

    if (g_right[root] != 0) {
        getMaxLeaf(g_right[root], currSum, maxLeaf);
    }
}

int MaxWeightLeaf(int* inOrder, int inOrderSize, int* postOrder, int postOrderSize)
{
    int root = buildTree(inOrder, inOrderSize, postOrder, postOrderSize);

    int maxLeaf = 0;
    getMaxLeaf(0, 0, &maxLeaf);
    return maxLeaf;
}