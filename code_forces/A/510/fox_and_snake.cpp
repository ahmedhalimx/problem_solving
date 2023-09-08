#include <iostream>
using namespace std;

int main() {
	int c {1}, r {1};
	bool downRight = true;

	cin >> c >> r;
	for (int cc {1}; cc <= c; ++cc) {
		if (cc % 2 != 0) {
			for (int rr {1}; rr <= r; ++rr)
				cout << '#';
			cout << endl;
		} else {
			if (downRight) {
				for (int rr {1}; rr <= (r - 1); ++rr)
					cout << ".";
				cout << "#" << endl;
				downRight = false;
			} else {
				cout << "#";
				for (int rr {2}; rr <= r; ++rr)
					cout << ".";
				cout << endl;
				downRight = true;
			}
		}
	}
	return (0);
}
