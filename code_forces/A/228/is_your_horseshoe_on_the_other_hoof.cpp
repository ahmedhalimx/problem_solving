#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
	unordered_set<int> h;
	int arr[4], r = 0;

	cin >> arr[0]  >> arr[1] >> arr[2] >> arr[3];
	for (int num : arr)
	{
		if (h.find(num) != h.end())
			++r;
		h.insert(num);
	}
	cout << r;
	return 0;
}
