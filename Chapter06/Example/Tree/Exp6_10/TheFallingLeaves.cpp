#include "TheFallingLeaves.h"

#include <stdlib.h>
#include <string.h>

#define MAX_N 100001

int g_sum[MAX_N];

void helper(int* preOrder, int preOrderSize, int *preOrderIndex, int *aux, int auxSize, int auxIndex)
{
    if (*preOrderIndex > preOrderSize) {
        return;
    }

    if (auxIndex < 0 || auxIndex >= auxSize) {
        return;
    }

    int index = (*preOrderIndex)++;
    if (preOrder[index] == -1) {
        return;
    }

    aux[auxIndex] += preOrder[index];
    helper(preOrder, preOrderSize, preOrderIndex, aux, auxSize, auxIndex - 1);
    helper(preOrder, preOrderSize, preOrderIndex, aux, auxSize, auxIndex + 1);
}

int *TheFallingLeaves(int* preOrder, int preOrderSize, int* returnSize)
{
    memset(g_sum, 0, sizeof(g_sum));

    int preOrderIndex = 0, auxIndex = MAX_N / 2;
    helper(preOrder, preOrderSize, &preOrderIndex, g_sum, MAX_N, auxIndex);

    int lo = auxIndex, hi = auxIndex;

    while (lo >= 0    && g_sum[lo] != 0) lo--;
    while (hi < MAX_N && g_sum[hi] != 0) hi++;

    lo++; hi--;

    int* ret = (int*)malloc((hi - lo + 1) * sizeof(int));
    for (int i = 0; i < hi - lo + 1; i++) {
        ret[i] = g_sum[lo + i];
    }

    *returnSize = hi - lo + 1;
    return ret;
}