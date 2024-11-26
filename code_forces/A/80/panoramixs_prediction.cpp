#include <iostream>
using namespace std;
using ull = unsigned long long;

int main(void) {
	ull n {0}, m {0}, res {0};

	cin >> n >> m;
	for (int i = n + 1; i <= 50; ++i) {
		bool is_prime = true;

		for (int j = 2; j < i; ++j) {
			if (i % j == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) {
			res = i;
			break;
		}
	}
	(res == m && res != 0) ? cout << "YES" : cout << "NO";
	return 0;
}
