#include "pangram.h"

#define A_ASCII 65

/**
 * is_pangram - checks if a given string is a pangram
 * description: a sentence is a panagram when all alphabets
 * 							occurs in the sentence
 *
 * @sentence: a string to check for
 *
 * return: if the sentence is a pangram returns (true),
 * 				otherwise returns (false).
 */

bool is_pangram(const char *sentence) {
	if (!sentence || !(*sentence)) return (false);
	const int size = strlen(sentence);
	bool attendance[26] = {0};

	for (int i = 0; i < size; ++i) {
		if (!isalpha(sentence[i])) continue;
		
		const int char_ascii = toupper(sentence[i]);
		attendance[(char_ascii - A_ASCII)] = true;
	}
	for (int i = 0; i < 26; ++i)
		if (attendance[i] != true) return (false);

	return (true);
}
