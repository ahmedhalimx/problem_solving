#include <iostream>
#include <vector>
using namespace std;

int main() {
	string s {""};
	size_t q {0};
	size_t l {0}, r {0};
	vector<size_t> res;

	cin >> s >> q;
	for (size_t i {0}; i < q; ++i) {
		size_t x {0};

		cin >> l >> r;
		--l, --r;
		for (size_t i = l; i < r; ++i)
			if (s[i] == s[i + 1]) ++x;

		res.push_back(x);
	}
	for (size_t i {0}; i < res.size(); ++i) cout << res.at(i) << endl;
	return (0);
}
