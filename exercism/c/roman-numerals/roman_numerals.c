#include "roman_numerals.h"

char *to_roman_numeral(unsigned int number) {
	char *result = calloc(16, sizeof(char));
	int ch_indx = 0;

	while (number != 0) {
		for (int i = 0; i <= 12; ++i)
			if (NUMERAL_VALUES[i] % number == NUMERAL_VALUES[i] 
					|| NUMERAL_VALUES[i] == number)
			{
				switch (NUMERAL_VALUES[i])
				{
					case (CM): case (CD):
					case (XC): case (XL):
					case (IX): case (IV):
						result[ch_indx++] = NUMERAL_CHARS[i][0];
						result[ch_indx] = NUMERAL_CHARS[i][1];
						number -= NUMERAL_VALUES[i];
						++ch_indx; break;
					default:
						result[ch_indx] = NUMERAL_CHARS[i][0];
						number -= NUMERAL_VALUES[i];
						++ch_indx; break;
				}
				break;
			}
	}
	result = realloc(result, sizeof(char) * (ch_indx + 1));
	return (result);
}
