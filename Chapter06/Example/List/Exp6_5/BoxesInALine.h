#ifndef __BOXES_IN_A_LINE_H_
#define __BOXES_IN_A_LINE_H_

typedef enum {
    OPR_MOVE_X2Y_LEFT = 0,
    OPR_MOVE_X2Y_RIGHT,
    OPR_SWAP_X_AND_Y,
    OPR_BUTT
} Operation;

typedef unsigned int OperationUint32Enum;

void InitLineBox(int n);
void OperateBox(OperationUint32Enum opr, int X, int Y);
void InvertBox();

void PrintLinkBox();

#endif