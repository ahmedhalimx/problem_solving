#include <cctype>
#include <iostream>
#include <set>
using namespace std;

int main(int argc, char **argv) {
	size_t num_chars {0};
	string sentence {""};
	set<char> chars_set;

	cin >> num_chars;
	cin >> sentence;

	for (int i = 0; i < num_chars; ++i) {
		char ch = tolower(sentence[i]);
		chars_set.insert(ch);
	}

	for (char ch = 'a'; ch <= 'z'; ++ch) {
		if (chars_set.find(ch) == chars_set.end())
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}
