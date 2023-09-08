#include <iostream>
using namespace std;

int main() {
	size_t c {0}, max {0}, min {0}, amazing {0};

	cin >> c >> max;
	min = max;
	for (int i {1}; i < c; ++i) {
		int number {0};

		cin >> number;
		if (number > max) {
			max = number;
			++amazing;
		} 
		else if (number < min) {
			min = number;
			++amazing;
		}
	}
	cout << amazing << endl;
	return (0); 
}
