#include "atbash_cipher.h"

#define ATBASH_LAST_INDEX 219
#define WHITE_SPACE ' '

char *atbash_encode(const char *input) {
	if (!input) return (NULL);
	size_t counter = 0, idx = 0;
	char *encoded = calloc(100, sizeof(char));
	char char_encoded = '\0';

	for (size_t i = 0; input[i] != '\0'; ++i) {
		if (ispunct(input[i]) || isspace(input[i])) continue;
		if (counter == 5) {
			encoded[idx] = WHITE_SPACE;
			counter = 0;
			++idx;
		}
		if (isdigit(input[i])) {
			encoded[idx] = input[i];
			++counter, ++idx;
			continue;
		}
		char_encoded = ATBASH_LAST_INDEX - tolower(input[i]);
		encoded[idx] = char_encoded;
		++counter, ++idx;
	}
	encoded = realloc(encoded, (idx + 1) * sizeof(char));
	encoded[idx] = '\0';
	return (encoded);
}

char *atbash_decode(const char *input) {
	if (!input) return (NULL);
	char *decoded = calloc(100, sizeof(char));
	char char_decoded = '\0';
	size_t idx = 0;

	for (size_t i = 0; input[i] != '\0'; ++i) {
		if (isspace(input[i])) continue;
		if (isdigit(input[i])) {
			decoded[idx] = input[i];
			++idx;
			continue;
		}
		char_decoded = ATBASH_LAST_INDEX - tolower(input[i]);
		decoded[idx] = char_decoded;
		++idx;
	}
	decoded = realloc(decoded, (idx + 1) * sizeof(char));
	decoded[idx] = '\0';
	return (decoded);
}
