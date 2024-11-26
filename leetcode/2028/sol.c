#include <stdio.h>
#include <stdlib.h>

#define MAX_DICE_VAL 6
#define MIN_DICE_VAL 1
#define SUCH_ARRAY_CANNOT_EXSIST(A, S) (((A / S) > MAX_DICE_VAL) || ((A / S) < MIN_DICE_VAL))

int sum(int *arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; ++i) sum += arr[i];
	return sum;
}

int main(void) {
	int rolls[] = {1, 5, 6}, rollsSize = 3;
	int n = 4, mean = 3;
	int total_ncount = rollsSize + n;
	int missing_sum = (total_ncount * mean) - sum(rolls, rollsSize);

	if (SUCH_ARRAY_CANNOT_EXSIST(missing_sum, total_ncount)) { return NULL; }

	printf("ms: %d\n", missing_sum);
	int result[n];

	for (int i = n - 1; i >= 0; --i) {
		int min = (MAX_DICE_VAL < (missing_sum - i))? MAX_DICE_VAL : (missing_sum - i);
		result[i] = min;
		missing_sum -= min;
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", result[i]);
	}
}
