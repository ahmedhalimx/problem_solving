#include <iostream>
using namespace std;

int main(){
	int m {0}, l {0}, r {0}, score {0};
	int dp[100005] {0};
	string s {""};

	cin >> s >> m;

	for (int i {1}; i < s.size(); ++i) {
		if (s[i]==s[i-1]) score++;
		dp[i] = score;
	}

	while (m--) {
		cin >> l >> r;
		cout << dp[r-1] - dp[l-1] << endl;
	}
	return (0);
}
