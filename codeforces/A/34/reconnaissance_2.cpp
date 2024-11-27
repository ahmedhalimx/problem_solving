#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	size_t n {0}, first {0}, second{0}, ir {0}, il {0};
	cin >> n;
	
	size_t arr[n];

	for (int i = 0; i < n; ++i){cin >> arr[i];}
	for (int i = 0; i < n - 1; ++i)
	{
		first = arr[i];
		second = arr[i+1];
		if (abs((float)(first-second)) < abs((float)(ir-il))) {
			ir = first;
			il = second;
		}
	}
	if (abs((float)(arr[n-1]-arr[0])) < abs((float)(ir-il))) {
		ir = arr[n-1];
		il = arr[0];
	};
	cout << ir << il;
	return 0;
}
