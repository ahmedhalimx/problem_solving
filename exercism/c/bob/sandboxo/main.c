#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *strtrem(char *str) {
	char *trem = calloc(strlen(str), sizeof(char));
	int idx = 0;

	for (int i = 0; str[i] != '\0'; ++i)
		if (str[i] != ' ' && str[i] != '\t') {
			trem[idx] = str[i];
			++idx;
		}

	if (idx == 0) {
		free(trem);
		return (NULL);
	}
	trem = realloc(trem, idx);
	trem[idx] = '\0';
	return (trem);
}

int main(int argc, char **argv) {
	char s[] = "    \t   \t   \t   \t\t\t\t";
	char *a = strtrem(s);

	if (a == NULL)
		printf("Empty");
	return (EXIT_SUCCESS);
}
