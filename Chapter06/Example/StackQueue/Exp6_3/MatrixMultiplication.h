#ifndef __MATRIX_MULTIPLICATION_H_
#define __MATRIX_MULTIPLICATION_H_

typedef struct {
    int rows;
    int cols;
} Matrix;

int MatrixMultiplication(Matrix *matrix, int matrixNum, char *expression);

#endif