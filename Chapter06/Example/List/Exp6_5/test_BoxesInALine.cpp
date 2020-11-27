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

    /* 1, 3, 5, 4, 6, 2 */
    InvertBox();

    OperateBox(OPR_MOVE_X2Y_LEFT, 6, 2);
    OperateBox(OPR_MOVE_X2Y_RIGHT, 4, 6);
    
    /* 3, 1, 5, 4, 6, 2 */
    OperateBox(OPR_MOVE_X2Y_LEFT, 1, 5);

    /* 3, 1, 5, 6, 4, 2 */
    OperateBox(OPR_MOVE_X2Y_RIGHT, 4, 6);

    /* 4, 3, 1, 5, 6, 2 */
    OperateBox(OPR_MOVE_X2Y_LEFT, 4, 3);

    /* 2, 3, 1, 5, 6, 4 */
    OperateBox(OPR_SWAP_X_AND_Y, 4, 2);

    PrintLinkBox();
}

int main(int argc, char **argv)
{
    test1();

    test2();
    
    return 0;
}