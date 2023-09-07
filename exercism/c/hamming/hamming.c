#include "hamming.h"

int compute(const char *lhs, const char *rhs) {
    size_t i;
    size_t hamming_distance = 0;

   if (strlen(lhs) != strlen(rhs))
         return -1;

    for (i = 0; rhs[i] != '\0'; ++i)
        if (rhs[i] != lhs[i])
            ++hamming_distance;

    return hamming_distance;
}
