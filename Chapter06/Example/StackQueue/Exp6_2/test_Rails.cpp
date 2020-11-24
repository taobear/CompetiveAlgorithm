#include "Rails.h"

#include <stdio.h>

void test1()
{
    int rails[] = {5, 4, 1, 2, 3};
    int railsSize = sizeof(rails) / sizeof(*rails);

    printf("test1(): %d\n", isPossibleRails(rails, railsSize));
}

void test2()
{
    int rails[] = {5, 4, 3, 2, 1};
    int railsSize = sizeof(rails) / sizeof(*rails);

    printf("test2(): %d\n", isPossibleRails(rails, railsSize));
}

void test3()
{
    int rails[] = {4, 5, 3, 1, 2};
    int railsSize = sizeof(rails) / sizeof(*rails);

    printf("test3(): %d\n", isPossibleRails(rails, railsSize));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    return 0;
}