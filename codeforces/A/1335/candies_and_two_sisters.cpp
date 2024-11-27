#include <charconv>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	size_t t {0};

	cin >> t;
	for (size_t i {0}; i < t; ++i) {
		size_t n_candles {0};

		cin >> n_candles;
		cout << (size_t)ceil((n_candles - 1) / 2) << endl;
	}
	return (0);
}
