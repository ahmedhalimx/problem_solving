#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	size_t size {0},
		   max_subarray {1},
		   current_subarray_size {1},
		   pre_value {0};

	cin >> size;
	for (int i {0}; i < size; ++i) {
		int value {0};
		
		cin >> value;
		if (i == 0) {
			pre_value = value;
			continue;
		}
		if (value <= pre_value) {
			if (current_subarray_size > max_subarray)
				max_subarray = current_subarray_size;

			current_subarray_size = 1;
			pre_value = value;
			continue;
		}
		pre_value = value;
		++current_subarray_size;
	}
	(current_subarray_size > max_subarray) ?
		cout << current_subarray_size : cout << max_subarray;
	return (0);
}
