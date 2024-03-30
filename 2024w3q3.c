#include <stdio.h>

int ilog2(int i)
{
    int log = -1;
    while (i) {
        i >>= 1;
        log++;
    }
    return log;
}

int main(){
    printf("%d\n", ilog2(8));
    return 0;
}