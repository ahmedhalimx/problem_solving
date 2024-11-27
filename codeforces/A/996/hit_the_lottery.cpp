#include <iostream>
using namespace std;

int main() {
	int n {0}, r {0};

	cin >> n;
	while (n != 0) {
		if (n - 100 >= 0)
			n -= 100;
		else if (n - 20 >= 0)
			n -= 20;
		else if (n - 10 >= 0)
			n -= 10;
		else if (n - 5 >= 0)
			n -= 5;
		else
			--n;
		++r;
	}
	cout << r << endl;
	return (0);
}
