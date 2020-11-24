#include "BrokenKeyBoard.h"

#include <stdio.h>
#include <malloc.h>

void test1()
{
    char input[] = "This_is_a_[Beiju]_text";
    char *output = BrokenKeyBoard(input);

    printf("test1(): %s\n", output);

    free(output);
}

void test2()
{
    char input[] = "[[]][][]Happy_Birthday_to_Tsinghua_University.";
    char *output = BrokenKeyBoard(input);

    printf("test2(): %s\n", output);

    free(output);
}

int main(int argc, char **argv)
{
    test1();

    test2();

    return 0;
}