#include <iostream>
#include <set>
#include <string>
using namespace std;

int main(int argc, char **argv) {
	string letters {""};
	set<char> unique_chars;

	getline(cin, letters);
	for (auto &ch : letters) {
		if (ch == '}' || ch == '{' || ch == ',' || ch == ' ')
			continue;
		unique_chars.insert(ch);
	}
	if (unique_chars.size())
		cout << unique_chars.size() << endl;
	else
		cout << 0 << endl;
	return (0);
}
