#include "BrokenKeyBoard.h"

#include <string.h>
#include <malloc.h>

char* BrokenKeyBoard(char* input)
{
    int len = strlen(input);
    int next[len + 1];
    int last = len, curr = len;

    next[len] = len;
    for (int i = 0; i < len; i++) {
        if (input[i] == '[') {
            curr = len;
        } else if (input[i] == ']') {
            curr = last;
        } else {
            next[i] = next[curr];
            next[curr] = i;
            if (curr == last) {
                last = i;
            }

            curr = i;
        }
    }

    char *result = (char*)malloc(sizeof(char) * (len + 1));
    int rsltIter = 0;
    for (int i = next[len]; i != len; i = next[i]) {
        result[rsltIter++] = input[i];
    }

    result[rsltIter] = '\0';
    
    return result;
}