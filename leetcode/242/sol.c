#include <stdio.h>
#include <stdbool.h>

#define POS(a) (a - 'a')
bool isAnagram(char* s, char* t) {
	int carr[26] = {0};
	
	for (int i = 0; s[i] != '\0'; ++i) {
		carr[POS(s[i])] += 1;
	}

	for (int i = 0; t[i] != '\0'; ++i) {
		carr[POS(s[i])] -= 1;
	}

	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] != 0) return false;
	}
	return true;
}
