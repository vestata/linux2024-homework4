#include <stdio.h>

unsigned popcount_naive(unsigned v)
{
    unsigned n = 0;
    while (v)
        v &= (v - 1), n = -(~n);
    return n;
}

int main(){
    popcount_naive(10);
    return 0;
}