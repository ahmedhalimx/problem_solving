#include <iostream>
#include <vector>
using namespace std;
 
int main() {
	int number_of_contestants {0}, chosen_contestant_place {0},
			chosen_contestant_score {0}, result {0};

	cin >> number_of_contestants >> chosen_contestant_place;
	vector<int> contestants(number_of_contestants);

	for (size_t i {0}; i < number_of_contestants; ++i) {
		int ith_place_score {0};

		cin >> ith_place_score;
		contestants[i] = ith_place_score;
	}
	chosen_contestant_score = contestants[chosen_contestant_place - 1];
	
	for (size_t i {0}; i < number_of_contestants; ++i)
		if (contestants.at(i) > 0
				&& contestants.at(i) >= chosen_contestant_score) ++result;
 
	cout << result << endl;
	return 0;
}
