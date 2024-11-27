#include <iostream>
#include <string>
using namespace std;

int main()
{
	string i {""};
	cin >> i;
	if (i.find('H') != string::npos
		|| i.find('Q') != string::npos
		|| i.find('9') != string::npos)
	{
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
}
