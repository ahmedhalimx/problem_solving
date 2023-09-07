#include "armstrong_numbers.h"

int getNumberOfDigits(int number) {
    int nm_of_digits = 0;

    while (number != 0) {
        number /= 10;
        ++nm_of_digits;
    }
    return (nm_of_digits);
}

bool is_armstrong_number(int candidate) {
    int sum = 0;
    int nm_of_digits = getNumberOfDigits(candidate);

    for (int i = candidate; i != 0; i /= 10) {
        int digit = i % 10;
        int n = 1;

        for (int j = 0; j < nm_of_digits; j++) {
            n *= digit;
        }
        sum += n;
    }
    return (sum == candidate);
}
