#include <iostream>
using namespace std;

int main() {
	int n_problems {0}, timeleft {0}, r {0};

	cin >> n_problems >> timeleft;
	timeleft = 240 - timeleft;

	for (int i {1}; i <= n_problems; ++i) {
		int x = 5 * i;
		if (timeleft - x >= 0) {
			timeleft -= x;
			++r;
		}
	}
	cout << r << endl;
	return (0);
}
