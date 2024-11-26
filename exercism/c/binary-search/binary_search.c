#include "binary_search.h"

/**
 * binary_search - implements the binary search algorithm
 *
 * @value: integer to search for
 * @arr: array to search in for value
 * @lenght: array's length
 *
 * return: address of value on success, (NULL) otherwise
 */

const int *binary_search(int value, const int *arr, size_t length) {    
	int right = length, left = 0;

	if (arr == NULL) return NULL;
	while (left < right) {
		int middle_idx = left + ((right - left) / 2);

		if (arr[middle_idx] == value) return (&arr[middle_idx]);
		if (arr[middle_idx] > value) right = middle_idx;
		if (arr[middle_idx] < value) left = middle_idx + 1;
	}
	return (NULL);
}
