#include "anagram.h"

bool samechrcount(const char *s1, const char *s2) {
	bool char_exists = false, status_success = true;
	int s1_score = 0, s2_score = 0;

	for (size_t i = 0; s1[i] != '\0'; ++i) {
		for (size_t j = 0; s2[j] != '\0'; ++j)
			if (s2[j] == s1[i])
			{
				char_exists = true;
				break;
			}
		if (!char_exists) status_success = false;
		s1_score += s1[i], s2_score += s2[i];
		char_exists = false;
	}
	return (status_success && (s1_score == s2_score));
}

void find_anagrams(const char *subject, candidates_t *candidates) {
	if (!candidates) return;
	if (!subject)
	{
		for (size_t i = 0; i < candidates->count; ++i)
			candidates->candidate[i].is_anagram = UNCHECKED;
		return;
	}
	char s[MAX_STR_LEN] = "\0";

	for (size_t i = 0; subject[i] != '\0'; ++i)
		s[i] = tolower(subject[i]);

	for (size_t i = 0; i < candidates->count; ++i)
	{
		char cand_word[MAX_STR_LEN] = "\0";
		size_t j = 0;

		for (j = 0; candidates->candidate[i].word[j] != '\0'; ++j)
			cand_word[j] = tolower(candidates->candidate[i].word[j]);

		if (strcmp(cand_word, s) == 0 || !samechrcount(cand_word, s))
			candidates->candidate[i].is_anagram = NOT_ANAGRAM;
		else 
			candidates->candidate[i].is_anagram = IS_ANAGRAM;
	}
}
