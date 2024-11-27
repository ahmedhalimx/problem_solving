#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	int t {0}, number_a {0}, number_b {0};

	cin >> t;
	for (int i {0}; i < t; ++i) {
		cin >> number_a >> number_b;
		if (number_a % number_b == 0)
		{
			cout << 0 << endl;
			continue;
		}
		cout << number_b - (number_a % number_b) << endl;
	}
	return (0);
}
