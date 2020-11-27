#include "BoxesInALine.h"

#include <stdio.h>

#define MAX_BOX_NUM 1000001

typedef struct {
    int left;
    int right;
} ListNode;

ListNode list[MAX_BOX_NUM];
int listNum = 0;

bool isInvert = false;

void link(int L, int R)
{
    list[L].right = R;
    list[R].left = L;
}

void InitLineBox(int n)
{
    listNum = n + 1;
    for (int i = 0; i <= n; i++) {
        list[i].left  = (i + n) % (n + 1);
        list[i].right = (i + 1) % (n + 1);
    }

    isInvert = false;
}

void OperateBox(OperationUint32Enum opr, int X, int Y)
{
    if (opr >= OPR_BUTT) {
        return;
    }

    if (isInvert && opr != OPR_SWAP_X_AND_Y) {
        opr = OPR_MOVE_X2Y_RIGHT - opr;
    }

    if (opr == OPR_MOVE_X2Y_LEFT && list[Y].left == X) {
        return;
    }

    if (opr == OPR_MOVE_X2Y_RIGHT && list[Y].right == X) {
        return;
    }

    int LX = list[X].left;
    int RX = list[X].right;
    int LY = list[Y].left;
    int RY = list[Y].right;

    if (opr == OPR_MOVE_X2Y_LEFT) {
        link(LX, RX); link(LY, X); link(X, Y);
    } else if (opr == OPR_MOVE_X2Y_RIGHT) {
        link(LX, RX); link(Y, X); link(X, RY);
    } else {
        if (RY == X) {
            link(LY, X); link(X, Y); link(Y, RX); 
        } else if (LY == X) {
            link(LX, Y); link(Y, X); link(X, RY);
        } else {
            link(LX, Y); link(Y, RX);
            link(LY, X); link(X, RY);
        }
    }
}

void InvertBox()
{
    isInvert = !isInvert;
}

void PrintLinkBox()
{
    if (!isInvert) {
        for (int i = list[0].right; i != 0; i = list[i].right) {
            printf(" %d", i);
        }
    } else {
        for (int i = list[0].left; i != 0; i = list[i].left) {
            printf(" %d", i);
        }
    }

    printf("\n");
}
