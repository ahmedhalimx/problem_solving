#include <stdio.h>

int strfind(char *s, char c) {
	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] == c) return i;
	}
	return -1;
}

char* reversePrefix(char* wrd, char c) {
	int idch = strfind(wrd, c);

	for (int i = 0, j = idch; i < j; ++i, --j) {
		char tmp = wrd[j];
		wrd[j] = wrd[i];
		wrd[i] = tmp;
	}

	return wrd;
}

int main(void) {
	printf("res: %s\n", reversePrefix("abcdefd", 'd'));
}
