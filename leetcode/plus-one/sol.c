#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int *plusOne(int *digits, int digitsSize, int *resultSize)
{
	int *result = calloc(digitsSize + 1, sizeof(int));
	int carry = 0;
	
	memcpy(result, digits, digitsSize * sizeof(int));
	for (int i = digitsSize - 1; i >= 0; --i) {
		if (digits[i] == 9) {
			result[i] = 0, carry = 1;
			continue;
		}
		result[i] += 1, carry = 0;
		break;
	}

	if (carry == 0) {
		*resultSize = digitsSize;
		result = realloc(result, digitsSize * sizeof(int));
	} else {
		result[0] = 1;
		*resultSize = digitsSize + 1;
	}
	return result;
}

int main() {
	int isize = 3, rsize = 0;
	int input[] = {9,9,9};
	int *a = plusOne(input, isize, &rsize);

	for (int i = 0; i < rsize; ++i) {
		printf(" %d ", a[i]);
	}
	free(a);
}
