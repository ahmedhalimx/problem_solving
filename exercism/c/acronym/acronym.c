#include "acronym.h"

#define COMMA ','
#define APOSTROPHE '\''

/**
 * abbreviate - abbreviates a given string
 *
 * @phrase: the string which will be abbreviated
 *
 * return: (NULL) if phrase is NULL or empty,
 * 				the abbriviated string otherwise
 */

char *abbreviate(const char *phrase) {
	if (!phrase || !(*phrase)) return (NULL);

	char *acronym = calloc(strlen(phrase), sizeof(char));
	bool read_char = true;
	size_t length = 0;

	for (size_t i = 0; phrase[i] != '\0'; ++i) {
		char c = toupper(phrase[i]);

		if (!isalpha(c) && c != APOSTROPHE && c != COMMA) {
			read_char = true;
			continue;
		}

		if (read_char) {
			acronym[length] = c;
			read_char = false;
			++length;
		}
	}
	acronym[length] = '\0';
	acronym = realloc(acronym, sizeof(char) * (length + 1));
	return (acronym);
}
