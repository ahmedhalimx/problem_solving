#include "difference_of_squares.h"


unsigned int sum_of_squares(unsigned int number) {
    unsigned int sum_of_squares = 0;
    unsigned int i;

    for (i = 1; i <= number; ++i) {
        sum_of_squares += i * i;
    }

    return sum_of_squares;
}

unsigned int square_of_sum(unsigned int number) {
    unsigned int square_of_sums = 0;
    unsigned int i;

    for (i = 1; i <= number; ++i) {
        square_of_sums += i;
    }

    square_of_sums *= square_of_sums;
    return square_of_sums;
}

unsigned int difference_of_squares(unsigned int number) {
    return square_of_sum(number) - sum_of_squares(number);
}
