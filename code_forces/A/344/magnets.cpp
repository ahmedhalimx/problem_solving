#include <iostream>
using namespace std;

int main(int argc, char **argv) {
	int number_of_magnets {0}, number_of_groups {0};
	string current_magnet_position {""}, previous_magnet_position {""};

	cin >> number_of_magnets;
	for (int i = 0; i < number_of_magnets; ++i) {
		cin >> current_magnet_position;
		if (current_magnet_position == previous_magnet_position)
			continue;
		++number_of_groups;
		previous_magnet_position = current_magnet_position;
	}
	cout << number_of_groups << endl;
	return 0;
}
