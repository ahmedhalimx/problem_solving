#include <iostream>
#include <set>
using namespace std;

int main(int argc, char **argv) {
	int target {0}, levels_for_X {0}, levels_for_Y {0};
	set<int> passable_levels;

	cin >> target >> levels_for_X;
	for (int i = 0; i < levels_for_X; ++i) {
		int level {0};
		cin >> level;
		passable_levels.insert(level);
	}

	cin >> levels_for_Y;
	for (int i = 0; i < levels_for_Y; ++i) {
		int level {0};
		cin >> level;
		passable_levels.insert(level);
	}

	if (passable_levels.size() != target)
		cout << "Oh, my keyboard!\n";
	else
		cout << "I become the guy.\n";
	return 0;
}
