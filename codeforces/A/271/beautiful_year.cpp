#include <iostream>
#include <set>
using namespace std;

int main(int argc, char **argv) {
	size_t given_year {0}, beautiful_year {0};

	cin >> given_year;
	beautiful_year = given_year;
	while (true)
	{
		set<size_t> digits {
			(beautiful_year / 1000),
			(beautiful_year / 100) % 10,
			(beautiful_year / 10) % 10,
			beautiful_year % 10
		};

		if (digits.size() == 4 && beautiful_year > given_year) {
			cout << beautiful_year << endl;
			return (0);
		}
		++beautiful_year;
	}
}
