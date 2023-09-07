#ifndef RATIONAL_NUMBERS_H
#define RATIONAL_NUMBERS_H

#include <stdint.h>
#include <stdlib.h>
#include <math.h>


typedef struct rational_s {
    int16_t numerator;
    int16_t denominator;
} rational_t;

int16_t GCD(const int16_t n1, const int16_t n2);

rational_t add(rational_t r1, rational_t r2);
rational_t subtract(rational_t r1, rational_t r2);

rational_t multiply(rational_t r1, rational_t r2);
rational_t divide(rational_t r1, rational_t r2);


rational_t exp_rational(rational_t r, int16_t n);
float exp_real(uint16_t x, rational_t r);

rational_t absolute(rational_t r);
rational_t reduce(rational_t r);

#endif
