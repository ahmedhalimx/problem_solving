#include "rational_numbers.h"

/**
 * GCD - Computes the greatest common divisor, givien two integers
 * 
 * @n1: first integer
 * @n2: Second integer
 *
 * Return: the greatest common divisor
 */
int16_t GCD(const int16_t  n1, const int16_t n2) {
    int i;
    int gcd = 0;

    for(i = 1; i <= n1 || i <= n2; ++i)
        if (n1 % i == 0 && n2 % i == 0)
            gcd = i;

    return (gcd);
}

/**
 * absolute - Computes the absolute of a givien rational number
 *
 * @r: a rational number
 *
 * Return: the absolute of @r in its reduced form
 */
rational_t absolute(rational_t r) {
    r.numerator = abs(r.numerator);
    r.denominator = abs(r.denominator);

    return (reduce(r));
}

/**
 * reduce - Reduces a givien rational number to its lowest terms
 *
 * @r: a rational number
 *
 * Return: the reduced (or standard) form of @r
 */
rational_t reduce(rational_t r) {
    if (r.denominator < 0) {
        r.numerator *= -1;
        r.denominator *= -1;
    }
    int16_t gcd = GCD(r.numerator, r.denominator);

    r.numerator = (r.numerator / gcd);
    r.denominator = (r.denominator / gcd);

    return (r);
}

/**
 * add - Adds two rational numbers
 *
 * @r1: first rational number
 * @r2: Second rational number
 *
 * Return: the result of addition to its reduced form
 */
rational_t add(rational_t r1, rational_t r2) {
    rational_t r_result = {
        .numerator = (r1.numerator * r2.denominator) + (r2.numerator * r1.denominator),
        .denominator = r1.denominator * r2.denominator
    };

    return (reduce(r_result));
}

/**
 * subtract - Subtracts two rational numbers
 *
 * @r1: first rational number
 * @r2: Second rational number
 *
 * Return: the result of Subtraction to its reduced form
 */
rational_t subtract(rational_t r1, rational_t r2) {
    rational_t r_result = {
        .numerator = (r1.numerator * r2.denominator) - (r2.numerator * r1.denominator),
        .denominator = r1.denominator * r2.denominator
    };

    return (reduce(r_result));
}

/**
 * multiply - Multiplies two rational numbers
 *
 * @r1: first rational number
 * @r2: Second rational number
 *
 * Return: the result of multiplication to its reduced form
 */
rational_t multiply(rational_t r1, rational_t r2) {
    rational_t r_result = {
        .numerator = r1.numerator * r2.numerator,
        .denominator = r1.denominator * r2.denominator
    };

    return (reduce(r_result));
}

/**
 * divide - Divides two rational numbers
 *
 * @r1: first rational number
 * @r2: Second rational number
 *
 * Return: the result of division to its reduced form
 */
rational_t divide(rational_t r1, rational_t r2) {
    rational_t r_result = {
        .numerator = r1.numerator * r2.denominator,
        .denominator = r2.numerator * r1.denominator
    };

    return (reduce(r_result));
}

/**
 * exp_rational - Raises a rational number to an integer
 *
 * @r: a rational number
 * @n: an integer exponent
 *
 * Return: the real number @r raised to the power @n,
 * reduced to its standard form
 */
rational_t exp_rational(rational_t r, int16_t n) {
    rational_t r_result;

    if (n < 0) {
        r_result.numerator = pow(r.denominator, abs(n));
        r_result.denominator = pow(r.numerator, abs(n));
    } else {
        r_result.numerator = pow(r.numerator, n);
        r_result.denominator = pow(r.denominator, n);
    }

    return (reduce(r_result));
}

/**
 * exp_real - Raises an integer to a rational number
 *
 * @x: a positive integer
 * @r: a rational number as an exponent
 *
 * Return: the integer @x raised to the power @r,
 * reduced to its standard form
 */
float exp_real(uint16_t x, rational_t r) {
    return (pow(x, (double)r.numerator / (double)r.denominator));
}
