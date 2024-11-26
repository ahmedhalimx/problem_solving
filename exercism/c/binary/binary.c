#include "binary.h"

#define ZERO_ASCII 48

/**
 * convert - takes a binary number string form and
 * 					converts it to a decimal number integer
 *
 * @input: a string represinting a binary number
 *
 * return: on success returns the decimal number,
 * 				on failure returns (invalid)
 */

int convert(const char *input) {
	size_t decimal_number = 0;
	size_t bit_exponent = strlen(input) - 1;

	for (int i = 0; input[i] != '\0'; ++i, --bit_exponent) {
		size_t bit = ((size_t)input[i] - ZERO_ASCII);

		if (bit != 0 && bit != 1) return (INVALID);
		decimal_number += bit * (1 << bit_exponent);
	}
	return (decimal_number);
}

