#include "DroppingBalls.h"

#include <string.h>

int DroppingBalls(int D, int I)
{
    int maxLeaf = (1 << D);
    int switchState[maxLeaf];

    memset(switchState, 0, maxLeaf * sizeof(int));

    int result;
    for (int i = 0; i < I; i++) {
        int last = 1;
        for (int j = 0; j < D; j++) {
            int state = switchState[last];

            switchState[last] = !state;
            if (state == 0) {
                last = last * 2;
            } else {
                last = last * 2 + 1;
            }
        }

        result = last / 2;
    }

    return result;
}