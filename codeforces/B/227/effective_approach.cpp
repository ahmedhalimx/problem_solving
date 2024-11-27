#include <algorithm>
#include <iostream>
#include <vector>

#define N (1e5 + 1)

using namespace std;

int main(void)
{
	size_t n {0}, q {0}, vs {0}, ps {0};
	vector<size_t> nums, nums_table(N);

	cin >> n;
	for (size_t i = 0; i < n; ++i)
	{
		size_t val {0};

		cin >> val;
		nums.push_back(val);
		nums_table[val] = i;
	}
	cin >> q;
	for (size_t i = 0; i < q; ++i)
	{
	size_t elem {0};

		cin >> elem;
		vs += nums_table[elem] + 1;
		ps += n - nums_table[elem];
	}
	cout << vs << " " << ps;
	return 0;
}
