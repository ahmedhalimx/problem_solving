#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	int number_of_drinks {0};
	double volume_of_orange_juice {0.0};

	cin >> number_of_drinks;
	for (int i = 0; i < number_of_drinks; ++i) {
		int volume {0};

		cin >> volume;
		volume_of_orange_juice += volume;
	}
	volume_of_orange_juice /= number_of_drinks;
	cout.precision(14);
	cout << volume_of_orange_juice << endl;
	return (0);
}
