#include "reverse_string.h"

char *reverse(const char *value) {
	char *reversed_value = NULL;
	int size = 0;

	for (int i = 0; value[i] != '\0'; ++i)
		++size;

	reversed_value = malloc(sizeof(char) * size + 1);
	for (int i = 0; i <= size; ++i) {
		if (i != size) {
			reversed_value[i] = value[(size - 1) - i];
		} else {
			reversed_value[i] = '\0';
		}
	}
	return (reversed_value);
}
