#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void land_perimeter (size_t rows, size_t cols, const char land[rows][cols], char *result) {
	size_t land_count[cols];
	size_t total_land_parimeter = 0;
	
	for (size_t r = 0; r < rows; ++r) {
		for (size_t c = 0; c < cols; ++c) {
			if (land[r][c] != 'O') {
				land_count[c] += 1;
				continue;
			}
			total_land_parimeter += land_count[c] * land_count[c];
			land_count[c] = 0;
		}
	}

	for (size_t i = 0; i < cols; ++i) {
		if (land_count[i] == 0) continue; 
		total_land_parimeter += land_count[i] * land_count[i];
		land_count[i] = 0;
	}
	sprintf(result, "Total land perimeter: %zu", total_land_parimeter);
}
