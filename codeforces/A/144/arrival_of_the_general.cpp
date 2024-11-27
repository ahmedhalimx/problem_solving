#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
	size_t number_of_solderies {0}, highest {0},
		   h_index {0}, shortest {0}, s_index {0};

	cin >> number_of_solderies;
	vector<size_t> sequence_of_soldiers(number_of_solderies);

	for (size_t i {0}; i < sequence_of_soldiers.size(); ++i) {
		cin >> sequence_of_soldiers.at(i);
		if (i == 0) {
			highest = sequence_of_soldiers.at(i);
			shortest = sequence_of_soldiers.at(i);
			continue;
		}
		if (sequence_of_soldiers.at(i) > highest) {
			highest = sequence_of_soldiers.at(i);
			h_index = i;
		}
		if (sequence_of_soldiers.at(i) <= shortest) {
			shortest = sequence_of_soldiers.at(i);
			s_index = i;
		}
	}
	(h_index > s_index) ?
		cout << (sequence_of_soldiers.size() - 2) - s_index + h_index << endl
		:
		cout << (sequence_of_soldiers.size() - 1) - s_index + h_index << endl;
	return (0);
}
