#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int array_length { 0 }, no_queries { 0 };

	cin >> array_length >> no_queries;
	vector<vector<int>> a(array_length);

	for (int i = 0; i < array_length; ++i) {
		int size { 0 };

		cin >> size;
		for (int j = 0; j < size; ++j) {
			int element { 0 };

			cin >> element;
			a.at(i).push_back(element);
		}
	}

	for (int i = 0; i < no_queries; ++i)
	{
		int a_index { 0 }, k_index { 0 };

		cin >> a_index >> k_index;
		cout << a.at(a_index).at(k_index) << endl;
	}
	return (EXIT_SUCCESS);
}
