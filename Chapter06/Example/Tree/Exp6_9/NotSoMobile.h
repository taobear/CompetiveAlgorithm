#ifndef __NOT_SO_MOBILE_H_
#define __NOT_SO_MOBILE_H_

typedef struct {
    int W1;
    int D1;
    int W2;
    int D2;
} Balance;

bool NotSoMobile(Balance *bal, int balSize);

#endif