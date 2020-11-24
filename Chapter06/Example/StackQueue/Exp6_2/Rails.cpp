#include "Rails.h"

bool isPossibleRails(int *rails, int railsSize)
{
    int railsStack[railsSize];
    int stackSize = 0;

    int i = 0, j = 0; 
    
    while (j < railsSize) {
        if (rails[j] == i + 1) {
            j++; i++;
        } else if (stackSize != 0 && rails[j] == railsStack[stackSize - 1]) {
            j++; stackSize--;
        } else if (i < railsSize) {
            railsStack[stackSize++] = i + 1;
            i++;
        } else {
            break;
        }
    }

    return j == railsSize;
}