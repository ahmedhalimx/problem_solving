#ifndef ALL_YOUR_BASE_H
#define ALL_YOUR_BASE_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <memory.h>

#define DIGITS_ARRAY_SIZE 64

enum base_type
{
	BIN = 2,
	TRI = 3,
	OCT = 8,
	DEC = 10,
	HEX = 16
};

int8_t rebase(int8_t input_digits[], int16_t input_base,
	      int16_t output_base, size_t input_length);

#endif
