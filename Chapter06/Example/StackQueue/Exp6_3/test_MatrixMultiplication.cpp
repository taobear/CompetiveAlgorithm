#include "MatrixMultiplication.h"

#include <stdio.h>

void test1()
{
    Matrix A = {50, 10}, B = {10, 20}, C = {20, 5};
    Matrix mat[] = {A, B, C};

    char expression[] = "(A(BC))";

    printf("test1(): %d\n", MatrixMultiplication(mat, 3, expression));
}

void test2()
{
    Matrix A = { 50, 10 }, B = { 10, 20 }, C = { 20, 5 };
    Matrix mat[] = { A, B, C };

    char expression[] = "((AB)C)";

    printf("test1(): %d\n", MatrixMultiplication(mat, 3, expression));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}