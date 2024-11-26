#ifndef ROMAN_NUMERALS_H
#define ROMAN_NUMERALS_H

#include <stdlib.h> 


typedef enum {
	M = 1000, CM = 900,
	D = 500, CD = 400,
	C = 100, XC = 90,
	L = 50, XL = 40,
	X = 10, IX = 9,
	V = 5, IV = 4,
	I = 1
} roman_numeral_t;


static const roman_numeral_t NUMERAL_VALUES[] = 
{ 
	M, CM, D, CD,
	C, XC, L, XL,
	X, IX, V, IV, I
};

static const char * const NUMERAL_CHARS[] = 
{ 
	"M", "CM", "D", "CD",
	"C", "XC", "L", "XL",
	"X", "IX", "V", "IV",
	"I"
};

char *to_roman_numeral(unsigned int number);

#endif
