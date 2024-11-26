#include <iostream>
#include <vector>
using namespace std;

int main() {
	int row {0}, actual_row {0}, col {0}, cakes_eaten {0};
	string cake_gred {""};
	bool suk = true;

	cin >> row >> col;
	for (int i = 0; i < row; ++i) {
		string input {""};

		cin >> input;
		if (input.find('S') == string::npos) {
			cakes_eaten += col;
			continue;
		}
		++actual_row;
		cake_gred.append(input);
	}
	row = actual_row;
	for (int i = 0; i < col; ++i) {
		int score {0};
		for (int j = 0; j < row - 1; ++j) 
			if (cake_gred.at(i + (j * col)) == 'S'
					|| cake_gred.at(i + ((j + 1) * col)) == 'S')
			{
				score = 0;
				suk = false;
				break;
			} else {
				score += 1;
				suk = true;
			}
		cakes_eaten += score;
	}
	if (suk)
		cakes_eaten += 2;
	cout << cakes_eaten << endl;
	return 0;
}
