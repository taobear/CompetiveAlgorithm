#include "MatrixMultiplication.h"

#include <string.h>
#include <ctype.h>
#include <stdio.h>

int MatrixMultiplication(Matrix *matrix, int matrixNum, char *expression)
{
    int explen = strlen(expression);

    int result = 0;

    Matrix stack[matrixNum];
    int stackSize = 0;
    for (int i = 0; i < explen; i++) {
        if (isalpha(expression[i])) {
            if (expression[i] - 'A' >= matrixNum) {
                printf("invalid expression %c", expression[i]);
                return -1;
            }

            stack[stackSize++] = matrix[expression[i] - 'A']; // push
        } else if (expression[i] == ')') {
            Matrix *m2 = &stack[--stackSize];
            Matrix *m1 = &stack[--stackSize];

            if (m1->cols != m2->rows) {
                printf("A * B can't multiply.");
                return -1;
            }

            result += m1->rows * m1->cols * m2->cols;

            stack[stackSize].rows = m1->rows;
            stack[stackSize].cols = m2->cols;
            stackSize++;
        }

    }

    return result;
}
