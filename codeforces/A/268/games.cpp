#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
	int teams {0}, number_of_exceptions {0};

	cin >> teams;
	vector<int> home_uniforms(teams);
	vector<int> guest_uniforms(teams);

	for (int i {0}; i < teams; ++i)
		cin >> home_uniforms.at(i) >> guest_uniforms.at(i);

	for (int i {0}; i < teams; ++i) {
			for (int j {0}; j < teams; ++j)
				if (home_uniforms.at(i) == guest_uniforms.at(j))
					++number_of_exceptions;
	}
	cout << number_of_exceptions << endl;
	return (0);
}
