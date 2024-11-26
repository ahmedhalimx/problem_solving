#include "rail_fence_cipher.h"

//HELLO -> HOELL
//H   		O
//	E		L
//		L
char *encode(char *text, size_t rails) {
	if (!text || rails == 0) return (NULL);
	if (!*text) return ("");

	int sequence = 2 * (rails  -  1);
	int length = strlen(text);
	int split = length / sequence;

	for (int i = 1; i <= rails)
}

char *decode(char *ciphertext, size_t rails);
