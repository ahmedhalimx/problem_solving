#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "word_count.h"


int parse(char *sentence) {
	/* Parsing */
	if (!sentence) return (0);
	const char *DELIM = "\t\r\n .,:;!?\'\"";
	char **word_list = calloc(MAX_WORDS, sizeof(char *));
	char *token = NULL;

	token = strtok(sentence, DELIM);
	for (int i = 0; token; ++i) {
		for (int j = 0; token[j] != '\0'; ++j) token[j] = tolower(token[j]);
		printf("%d:-> %s\n", i, token);
		token = strtok(NULL, DELIM);
	}
	return (0);
}

int main() {
	char sentence[] = "The Name Is Ahmed, and Ahmed's Cat is p'p Called lolo\n";
	parse(sentence);
	return (0);
}
