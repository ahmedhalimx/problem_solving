#include <iostream>
using namespace std;

int main() {
	int crimes {0}, officers {0}, now {0}, r {0};

	cin >> crimes;
	for (int i {0}; i < crimes; ++i) {
		cin >> now;
		if (now == -1) {
			if (officers != 0)
				--officers;
			else
				++r;
			continue;
		}
		officers += now;
	}
	cout << r << endl;
	return (0);
}
