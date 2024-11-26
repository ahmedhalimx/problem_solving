#include "pascals_triangle.h"

uint8_t **create_triangle(size_t rows) {
	uint8_t **triangle;

	if (rows == 0) {
		triangle = malloc(sizeof(uint8_t *));
		triangle[0] = calloc(1, sizeof(uint8_t));
		triangle[0][0] = 0;
		return (triangle);
	}

	triangle = calloc(rows, sizeof(uint8_t *) * rows);
	for (size_t i = 0; i < rows; ++i)
		triangle[i] = calloc(rows, sizeof(uint8_t) * rows);

	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j <= i; ++j) {
			if (j == i || j == 0)
				triangle[i][j] = 1;
			else 
				triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j]; 
		}
	}
	return (triangle);
}

void free_triangle(uint8_t **triangle, size_t rows) {
	for (size_t i = 0; i < rows; ++i)
		free(triangle[i]);

	free(triangle);
}

