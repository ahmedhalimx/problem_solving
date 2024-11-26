#include <iostream>
using namespace std;

int main() {
	int r {0}, d {0}, c {0}, ce {0};
	bool eatable = true;
	string c_vec {""};

	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		string input {""};
		
		cin >> input;
		if (input.find('S') == string::npos) {
			++d;
			ce += c;
			continue;
		}
		c_vec.append(input);
	}

	r -= d;
	for (int i = 0; i < c; ++i) {
		int s = 0;
		for (int j = 0; j < r - 1; ++j) {
			if (c_vec.at(i + (i * c)) == 'S' || c_vec.at(i + ((i + 1) * c)) == 'S') {
				eatable = false;
				break;
			}
			++s;
		}
	 (eatable) ? ce += s : eatable = true;
	}
	cout << ce << endl; 
	return 0;
}
