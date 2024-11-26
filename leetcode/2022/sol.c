#include <stdio.h>
#include <stdlib.h>

int** construct2DArray(int* original, int originalSize, int r, int c, int* returnSize, int** returnColumnSizes) {
	if ((r * c) != originalSize) return (int **){NULL};

	int **arr2D = calloc(r, sizeof(int *));
	int *colsizes = calloc(r, sizeof(int));
	int ri = 0, ci = 0;
	
	for (int i = 0; i < r; ++i) {
		arr2D[i] = calloc(c, sizeof(int));
		colsizes[i] = c;
	}

	for (int i = 0; i < originalSize; ++i) {
		if (ci == c) { ++ri; ci = 0; }
		arr2D[ri][ci++] = original[i];
	}
	*returnSize = r, *returnColumnSizes = colsizes;
	return arr2D;
}
