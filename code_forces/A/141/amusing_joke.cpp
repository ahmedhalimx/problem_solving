#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	string a {""}, b {""}, c {""};
	
	cin >> a >> b >> c;
	a.append(b);	
	if (a.length() != c.length()) {
		cout << "NO" << endl;
		return (0);
	}
	sort(a.begin(), a.end());
	sort(c.begin(), c.end());
	if (a == c)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return (0);
}
