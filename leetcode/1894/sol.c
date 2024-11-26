#include <stdio.h>
#include <stdlib.h>
int BSfindClosest(int *arr, int size, int t) {
	int candidate = arr[0], cidx = 0;
	int start = 0, end = size - 1;

	while (start <= end) {
		int mid = (start + end) / 2;

		if (abs(arr[mid] - t) < abs(candidate - t)) {
			candidate = arr[mid], cidx = mid;
		} else if (abs(arr[mid] - t) == abs(candidate - t)) {
			if (arr[mid] > candidate) {
				candidate = arr[mid];
				cidx = mid;
			}
		}

		if (arr[mid] == t) {
			return mid;
		} else if (arr[mid] < t) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}
	return cidx;
}

int chalkReplacer(int* chalk, int chalkSize, int k) {
	int idx = chalkSize - 1;
	int prefix_sum[chalkSize];

	prefix_sum[0] = chalk[0];
	for (int i = 1; i < chalkSize; ++i) {
		prefix_sum[i] = chalk[i] + prefix_sum[i - 1];
	}

	int start = 0, end = chalkSize - 1, last_index = -1;
	while (k > 0) {
		int result = BSfindClosest(prefix_sum, chalkSize, k);
		if (result > k) break;
		k -= prefix_sum[result];
		last_index = result;
	}
	return last_index;
}
int main() {
	int a[] = {5,1,5};
	int size = 3, k = 22;
	int x = chalkReplacer(a, size, k);

	printf("x: %d", x);
}
