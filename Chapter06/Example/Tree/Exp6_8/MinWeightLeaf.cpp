#include "MinWeightLeaf.h"

#define MAXV (10000 + 10)

int g_left[MAXV];
int g_right[MAXV];

int min(int a, int b)
{
    return a > b ? b : a;
}

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

void getMinLeaf(int root, int currSum, int *minLeaf, int *minSumLeaf)
{
    if (root == 0) {
        return;
    }

    currSum += root;
    if (g_left[root] == 0 && g_right[root] == 0) {
        if (currSum < *minSumLeaf) {
            *minLeaf = root;
            *minSumLeaf = currSum;
        } else if (currSum == *minSumLeaf) {
            *minLeaf = min(*minLeaf, root);
        }

        return;
    } 
    
    if (g_left[root] != 0) {
        getMinLeaf(g_left[root], currSum, minLeaf, minSumLeaf);
    }
    
    if (g_right[root] != 0) {
        getMinLeaf(g_right[root], currSum, minLeaf, minSumLeaf);
    }
}

int MinWeightLeaf(int* inOrder, int inOrderSize, int* postOrder, int postOrderSize)
{
    int root = buildTree(inOrder, inOrderSize, postOrder, postOrderSize);

    int minLeaf = MAXV, minSumLeaf = MAXV;
    getMinLeaf(root, 0, &minLeaf, &minSumLeaf);

    return minLeaf;
}