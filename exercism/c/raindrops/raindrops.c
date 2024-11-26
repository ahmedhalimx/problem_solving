#include "raindrops.h"
#include <stdio.h>
#include <string.h>

char *convert(char result[], int drops) {
	char *dynamic_string = calloc(16, sizeof(char));
	int i = 0;

	if (drops % 3 == 0) strcat(dynamic_string, "Pling"), ++i;
	if (drops % 5 == 0) strcat(dynamic_string, "Plang"), ++i;
	if (drops % 7 == 0) strcat(dynamic_string, "Plong"), ++i;
	
	if (i == 0) {
		free(dynamic_string);
		sprintf(result, "%d", drops);
		return (result);
	}

	strcpy(result, dynamic_string);
	free(dynamic_string);
	return (result);
}
