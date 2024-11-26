#include <algorithm>
#include <iostream>
using namespace std;
using ull = unsigned long long;

int main(void) {
	ull n {0}, b {0}, l{0}, m{0},
	s{0}, sa{0}, nl {0}, ns {0};

	cin >> n >> b >> l >> m >> s >> sa >> nl >> ns;
	ull t_l = (b * l) / (n * nl), t_m = (m * s) / n, t_s = sa / (n * ns);

	cout << min(min(t_l, t_m), t_s);
	return 0;
}
