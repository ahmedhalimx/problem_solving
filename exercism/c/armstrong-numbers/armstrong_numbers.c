#include "armstrong_numbers.h"

/**
 * number_of_digits - computes number of digits in
 * 										a given number
 *
 * @number: an integer
 *
 * return: Always (digits)
 */

int number_of_digits(int number) {
    int digits = 0;

		for (int i = number; i != 0; i /= 10) ++digits;
    return (digits);
}


/**
 * is_armstrong_number - checks if a given number is
 * 											an armstrongnumber
 *
 * @candidate: integer to be checked
 *
 * return: if the candidate is an armstrong number (true),
 * 				otherwise (false)
 */

bool is_armstrong_number(int candidate) {
    int num_digits = number_of_digits(candidate), sum = 0;

    for (int i = candidate; i != 0; i /= 10) {
        int digit = i % 10;
        sum += pow(digit, num_digits);
    }
    return (sum == candidate);
}
