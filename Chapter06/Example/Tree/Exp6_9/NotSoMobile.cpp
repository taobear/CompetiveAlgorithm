#include "NotSoMobile.h"

bool Helper(Balance* bal, int balSize, int *index, int *W)
{
    if (*index >= balSize) {
        return true;
    }

    int W1 = bal[*index].W1;
    int D1 = bal[*index].D1;
    int W2 = bal[*index].W2;
    int D2 = bal[*index].D2;

    bool flag1 = true;
    bool flag2 = true;
    if (!W1) { *index = *index + 1; flag1 = Helper(bal, balSize, index, &W1); }
    if (!W2) { *index = *index + 1; flag2 = Helper(bal, balSize, index, &W2); }

    *W = W1 + W2;
    return flag1 && flag2 && (W1 * D1 == W2 * D2);
}

bool NotSoMobile(Balance* bal, int balSize)
{
    int W = 0, index = 0;
    return Helper(bal, balSize, &index, &W);
}