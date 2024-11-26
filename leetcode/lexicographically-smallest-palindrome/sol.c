#include <string.h>
#include <stdio.h>

char *makeSmallestPalindrome(char *s)
{
	//[a] dasdad [a]
	int len = strlen(s);
	for (int i = 0, j = len - 1; i < (len / 2); ++i, --j) {
		if (s[i] == s[j]) continue;

		if (s[i] < s[j])
			s[j] = s[i];
		else 
			s[i] = s[j];
	}

	return s;
}

int main(void)
{
	char s[10] = "egcfe";
	printf("res: %s", makeSmallestPalindrome(s));
}
