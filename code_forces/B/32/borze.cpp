#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s {""}, r {""};

    cin >> s;
    int len = s.size();

    for (int i = 0; i < len; i++) {
        if (s[i] == '.') r += '0';
        else if(s[i] == '-' && s[i+1] == '.') { r += '1'; i++; }
        else if(s[i] == '-' && s[i+1] == '-') { r += '2'; i++; }
    }
    cout << r << endl;
    return 0;
}
