#include <stdlib.h>
#include <stdbool.h>

#define EXLAMATION_CODE (33);

int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z) {
	int idx = 0;
	int *res = calloc(n1, sizeof(char));
	bool accept_input = true;

	for (int i = 0; i < n1; ++i) {
		for (int j = 0; j < n2; ++j) {
			if (arr1[i] == arr2[j]) {
				accept_input = false;
				break;
			}
		}
		if (accept_input) {
			res[idx] = arr1[i];
			++idx;
		}
		accept_input = true;
	}
	*z = idx;
	res = realloc(res, (idx + 1) * sizeof(char));
	return (res);
}

int main(int argc, char **argv) {

	return (EXIT_SUCCESS);
}
