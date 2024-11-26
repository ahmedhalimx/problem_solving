#include <iostream>
#define NO_EQUALS ((a != b) && (b != c) && (a != c))

using namespace std;

int main() {
	int t {0}, n {0}, a {1},
	b {1}, c {1}, res {0};

	cin >> t;
	while (t != 0)
	{
		res = 0;
		cin >> n;
		a = b = c = n/3;
		--a;
		b -= 2;
		while (a+b+c < n) ++c;

		while (a%3 != 0 && b%3 != 0 & c%3 != 0 && NO_EQUALS)
		{
			
		}
		--t;
	}
}
