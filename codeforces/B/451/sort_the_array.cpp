#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> a;
	int size {0}, dif {0}, idx1 {0}, idx2 {0};

	cin >> size;
	for (int i = 0; i < size; ++i)
	{
		int z {0};
		cin >> z;
		a.push_back(z);
	}
	vector<int> a_cpy {a};
	sort(a.begin(), a.end());
	for (int i = 0; i < size; ++i)
	{
		int d = abs(a[i] - a_cpy[i]);
		if (d != 0) {
			if (d != dif && dif != 0) {
				cout << "no" << endl;
				return 0;
			}
		}
		dif = d;
		idx1 = a_cpy[i];
		idx2 = a[i];
	}
	cout << "yes" << endl;
	cout << idx1 << " " << idx2 << endl;
	return 0;
}
