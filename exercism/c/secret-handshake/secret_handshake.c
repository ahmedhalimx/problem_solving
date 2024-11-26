#include "secret_handshake.h"
#include <stdlib.h>

size_t *decode_number(size_t number) {
	char *binary_string = NULL;
	size_t *actions = calloc(5, sizeof(size_t));
	size_t length = 0, j = 0;

	for (int i = number; i > 0; i /= 2) ++length;

	binary_string = calloc(length + 1, sizeof(char));
	for (int i = number; i > 0; i /= 2) {
		if (i % 2 == 1)
			binary_string[j] = '1';
		else
			binary_string[j] = '0';
		++j;
	}

	for (int i = 0; binary_string[i] != '\0'; ++i)
		if (binary_string[i] == '1') 
			actions[i] = 1;

	free(binary_string);
	if (actions[0] == 0 
			&& actions[1] == 0 
			&& actions[2] == 0 
			&& actions[3] == 0)
	{
		free(actions);
		return (NULL);
	}
	return (actions);
}


const char **commands(size_t number) {
	if (number == 0) return (calloc(1, sizeof(char *)));
	size_t *actions = decode_number(number);
	size_t j = 0;

	if (!actions) return (calloc(1, sizeof(char *)));
	char **secret_handshake = calloc(4, sizeof(char *));
	
	if (actions[4] == 1) {
		for (int i = 3; i >= 0; --i) {
			if (actions[i] == 1)
				switch (i)
				{
					case (0):
						secret_handshake[j] = calloc(5, sizeof(char));
						secret_handshake[j] = "wink";
						++j; break;
					case (1):
						secret_handshake[j] = calloc(13, sizeof(char));
						secret_handshake[j] = "double blink";
						++j; break;
					case (2):
						secret_handshake[j] = calloc(16, sizeof(char));
						secret_handshake[j] = "close your eyes";
						++j; break;
					case (3):
						secret_handshake[j] = calloc(5, sizeof(char));
						secret_handshake[j] = "jump";
						++j; break;
				}
		}
	} else {
		for (int i = 0; i <= 3; ++i) {
			if (actions[i] == 1)
				switch (i)
				{
					case (0):
						secret_handshake[j] = calloc(5, sizeof(char));
						secret_handshake[j] = "wink";
						++j; break;
					case (1):
						secret_handshake[j] = calloc(13, sizeof(char));
						secret_handshake[j] = "double blink";
						++j; break;
					case (2):
						secret_handshake[j] = calloc(16, sizeof(char));
						secret_handshake[j] = "close your eyes";
						++j; break;
					case (3):
						secret_handshake[j] = calloc(5, sizeof(char));
						secret_handshake[j] = "jump";
						++j; break;
				}
		}
	}
	secret_handshake = realloc(secret_handshake, sizeof(char *) * j);
	free(actions);
	return ((const char **)secret_handshake);
}
