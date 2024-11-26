#include <iostream>
using namespace std;

int main(void) {
	size_t ls {0}, rs {0}, n {0};

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		size_t l {0}, r {0};

		cin >> l >> r;
		ls += l;
		rs += r;
	}
	ls = (ls > n/2) ? n - ls : ls; 
	rs = (rs > n/2) ? n - rs : rs;
	cout << ls + rs << endl;
	return 0;
}
