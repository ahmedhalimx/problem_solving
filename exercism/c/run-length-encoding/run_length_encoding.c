#include "run_length_encoding.h"

char *encode(const char *text) {
	if (!text) return (NULL);
	size_t repetition = 0, length = strlen(text), encoded_size = 0;
	char *encoded_text = calloc(length + 1, sizeof(char));
	char prev_chr = text[0];

	for (size_t i = 0; i <= length; ++i)
	{
		if (prev_chr == text[i]) {
			++repetition; 
			continue;
		}
		char *token = calloc(length, sizeof(char));

		if (repetition > 1)
			sprintf(token, "%lu%c", repetition, prev_chr);
		else
			sprintf(token, "%c", prev_chr);

		strcat(encoded_text, token);
		free(token);
		prev_chr = text[i];
		repetition = 1;
	}
	encoded_size = strlen(encoded_text);
	encoded_text = realloc(encoded_text, (encoded_size + 1) * sizeof(char));
	encoded_text[encoded_size] = '\0';
	return (encoded_text);
}


char *decode(const char *data) {
	if (!data) return (NULL);
	char repeated_char[1], *text = NULL;
	size_t repetition = 1, idx = 0, length = 0;
	bool already_read_the_digit = false;

	for (size_t i = 0; data[i] != '\0'; ++i) {
		if (isdigit(data[i])) {
			if (!already_read_the_digit) {
				repetition += atoi(&data[i]);
				already_read_the_digit = true;
			}
			continue;
		}
		length += repetition;
		repeated_char[0] = data[i];
		text = realloc(text, length * sizeof(char));
		while (repetition > 2) {
			text[idx] = repeated_char[0];
			--repetition;
			++idx;
		}
		text[idx] = repeated_char[0];
		repetition = 1;
		++idx;
		already_read_the_digit = false;
	}
	text = realloc(text, (length + 1) * sizeof(char));
	text[length] = '\0';
	return (text);
}
