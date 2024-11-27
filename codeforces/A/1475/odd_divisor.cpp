#include <iostream>
using namespace std;

int main()
{
	size_t t {0}, n {0};

	cin >> t;
	while (t != 0)
	{
		int f {0};

		cin >> n;
		f = (n - 1) / 2;

		((2 * f + 1) == n) ? cout << "YES\n" : cout << "NO\n";
		--t;
	}
}
