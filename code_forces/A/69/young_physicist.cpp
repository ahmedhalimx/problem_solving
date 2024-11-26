#include <iostream>
using namespace std;

int main()
{
	int n {0};

	cin >> n;
	int array[n][3];
	int csum[3] = {0, 0, 0};
	
	for (int i = 0; i < n; ++i)
		cin >> array[i][0] >> array[i][1] >> array[i][2];

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < n; ++j)
			csum[i] += array[j][i];
	
	if (csum[0] == 0 && csum[1] == 0 && csum[2] == 0)
		cout << "YES\n";
	else 
		cout << "NO\n"; 
	return 0;
}
