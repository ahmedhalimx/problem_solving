#include <iostream>
using namespace std;

int main() {
	string shape {""};
	int n {0}, r {0};

	cin >> n;
	for (int i {0}; i < n; ++i) {
		cin >> shape;
		switch (shape[0])
		{
		case ('T'):
			r += 4;
			break;
		case ('C'):
			r += 6;
			break;
		case ('O'):
			r += 8;
			break;
		case ('D'):
			r += 12;
			break;
		case ('I'):
			r += 20;
			break;
		}
	}
	cout << r << endl;
	return (0);
}
