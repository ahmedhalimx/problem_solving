#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool isPalindrome(char* s) {
	int len = strlen(s);
	int i = 0, j = len - 1;

	// "race a car"
	while (i <= j) {
		if (!isalnum(s[i])) {
			++i;
			continue;
		}
		if (!isalnum(s[j])) {
			--j;
			continue;
		}
		if (tolower(s[i]) != tolower(s[j])) return false;
		++i, --j;
	}
	return true;
}
