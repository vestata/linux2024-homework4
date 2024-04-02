#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <time.h>

typedef unsigned int uint32_t;

typedef struct {
    uint32_t (*func)(uint32_t);
    const char *file_name;
} Log2Impl;

uint32_t ilog2(uint32_t i)
{
    uint32_t log = 0;
    while (i) {
        i >>= 1;
        log++;
    }
    return log - 1;
}

uint32_t ilog2_2(uint32_t i)
{
    size_t result = 0;
    while (i >= 65536) {
        result += 16;
        i >>= 16;
    }
    while (i >= 256) {
        result += 8;
        i >>= 8;
    }
    while (i >= 16) {
        result += 4;
        i >>= 4;
    }
    while (i >= 2) {
        result += 1;
        i >>= 1;
    }
    return result;
}

uint32_t ilog32(uint32_t v)
{
    return (31 - __builtin_clz(v));
}

int main(){
    Log2Impl impls[] = {
        {.func = ilog2, .file_name = "out_ilog2.txt"},
        {.func = ilog2_2, .file_name = "out_ilog2_2.txt"},
        {.func = ilog32, .file_name = "out_ilog32.txt"}
    };

    for (int j = 0; j < sizeof(impls) / sizeof(impls[0]); j++) {
        FILE *fp = fopen(impls[j].file_name, "w");

        struct timespec start, end;
        int i;

        for (i = 1; i < 1000000 && i; i++) {
            clock_gettime(CLOCK_MONOTONIC, &start);
            impls[j].func(i);
            clock_gettime(CLOCK_MONOTONIC, &end);

            long long time = (long long) (end.tv_sec * 1e9 + end.tv_nsec) - \
                         (long long) (start.tv_sec * 1e9 + start.tv_nsec);  \

            fprintf(fp, "%u, %lld\n", i, time);
        }
        fclose(fp);
    }

    return 0;
}
