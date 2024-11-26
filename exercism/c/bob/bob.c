#include "bob.h"

#define QUESTION_MARK '?'

/*All possiable answers*/
static const char *ANSWER[5] = { 
	"Fine. Be that way!",
	"Calm down, I know what I'm doing!",
	"Sure.",
	"Whoa, chill out!",
	"Whatever."
};

/**
 * strtrim - creates a new string that does not
 * 					containg whitespace
 * @str: an argument to create the new string from
 *
 * return: a (NULL) if str is NULL, the trimed string otherwise
 */
char *strtrim(char *str) {
	if (!str || *str == '\0') return (NULL);
	char *trim = calloc(strlen(str), sizeof(char));
	size_t idx = 0;

	for (int i = 0; str[i] != '\0'; ++i) {
		if (!isspace(str[i])) {
			trim[idx] = str[i];
			++idx;
		}
	}

	if (idx == 0) {
		free(trim);
		trim = NULL;
	} else {
		trim = realloc(trim, idx + 1);
		trim[idx] = '\0';
	}
	return (trim);
}

/**
 * is_all_caps - check if all characters in str
 * 							are capital letters
 *
 * @str: string argument to check for
 * @length: string's length
 *
 * return: On success (true), otherwise (false)
 */
bool is_all_caps(char *str, size_t length) {
	if (!str || length == 0) return (false);
	bool contains_alphabet = false;

	for (size_t i = 0; i < length; ++i) {
		if (isalpha(str[i])) {
			contains_alphabet = true;
			if (str[i] == tolower(str[i]))
				return (false);
		}
	}
	return (contains_alphabet);
}

/**
 * hey_bob - returns bob's answer to the greeting
 *
 * @greeting: a greeting for bob
 *
 * return: if greeting is empty or NULL, returns ("Fine. Be that way!"),
 * 				else if it is a question and in all caps, returns
 * 															("Calm down, I know what I'm doing!"),
 * 				else if it is only a question, returns ("Sure."),
 * 				else if it is only in all caps, return ("Whoa, chill out!"),
 * 				else retruns ("Whatever.")
 */
const char *hey_bob(char *greeting) {
	char *trimed_greeting = strtrim(greeting);

	if (!trimed_greeting) return (ANSWER[0]);
	size_t length = strlen(trimed_greeting), choice = 0;
	bool isAllCaps = is_all_caps(trimed_greeting, length);
	bool isAQuestion = (trimed_greeting[length - 1] == QUESTION_MARK);

	if (isAQuestion && isAllCaps)
		choice = 1;
	else if (isAQuestion)
		choice = 2;
	else if (isAllCaps)
		choice = 3;
	else
		choice = 4;

	free(trimed_greeting);
	return (ANSWER[choice]);
}
