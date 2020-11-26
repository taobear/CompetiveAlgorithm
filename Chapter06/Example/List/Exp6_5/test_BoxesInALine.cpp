#include "BoxesInALine.h"

void test1()
{
    int n = 6;

    InitLineBox(n);

    OperateBox(OPR_MOVE_X2Y_LEFT, 1, 4);
    OperateBox(OPR_MOVE_X2Y_RIGHT, 3, 5);
    OperateBox(OPR_SWAP_X_AND_Y, 1, 6);

    InvertBox();

    PrintLinkBox();
}

void test2()
{
    int n = 6;

    InitLineBox(n);

    OperateBox(OPR_MOVE_X2Y_LEFT, 1, 4);
    OperateBox(OPR_MOVE_X2Y_RIGHT, 3, 5);
    OperateBox(OPR_SWAP_X_AND_Y, 1, 6);

    PrintLinkBox();
}

int main(int argc, char **argv)
{
    test1();

    test2();
    
    return 0;
}