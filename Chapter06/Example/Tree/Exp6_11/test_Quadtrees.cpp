#include "Quadtrees.h"

#include <stdio.h>

void test1()
{
    char tree1[] = "ppeeefpffeefe";
    char tree2[] = "pefepeefe";

    printf("test1(): %d\n", Quadtrees(tree1, tree2));
}

void test2()
{
    char tree1[] = "peeef";
    char tree2[] = "peefe";

    printf("test2(): %d\n", Quadtrees(tree1, tree2));
}

void test3()
{
    char tree1[] = "peeef";
    char tree2[] = "peepefefe";

    printf("test3(): %d\n", Quadtrees(tree1, tree2));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();
}