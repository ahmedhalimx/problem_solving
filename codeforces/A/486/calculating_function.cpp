#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char **argv) {
	long long number {0}, result {0};

	cin >> number;

	if (number % 2 == 0)
		result = number / 2;
	else
		result = ((number + 1) / 2) * (-1);

	cout << result << endl;
	return 0;
}
