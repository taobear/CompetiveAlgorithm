#include "NotSoMobile.h"

#include <stdio.h>

void test1()
{
    Balance bal[] = {
        {0, 2, 0, 4},
        {0, 3, 0, 1},
        {1, 1, 1, 1},
        {2, 4, 4, 2},
        {1, 6, 3, 2}
    };

    int balSize = sizeof(bal) / sizeof(*bal);

    printf("test1(): %d\n", NotSoMobile(bal, balSize));
}

int main(int argc, char **argv)
{
    test1();

    return 0;
}