#include "DroppingBalls.h"

#include <stdio.h>

void test1()
{
    printf("test1(): %d\n", DroppingBalls(4, 2));
}

void test2()
{
    printf("test2(): %d\n", DroppingBalls(3, 4));
}

void test3()
{
    printf("test3(): %d\n", DroppingBalls(10, 1));
}

void test4()
{
    printf("test4(): %d\n", DroppingBalls(2, 2));
}

void test5()
{
    printf("test5(): %d\n", DroppingBalls(8, 128));
}

void test6()
{
    printf("test6(): %d\n", DroppingBalls(16, 12345));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    test5();

    test6();

    return 0;
}