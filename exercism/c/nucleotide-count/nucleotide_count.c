#include "nucleotide_count.h"

char *count(const char *dna_strand) {
	int A_count = 0, T_count = 0, G_count = 0, C_count = 0;
	char *result = calloc(24, sizeof(char));

	for (int i = 0; dna_strand[i] != '\0'; ++i) {
		switch (dna_strand[i])
		{
			case('A'): ++A_count; break;
			case('T'): ++T_count; break;
			case('G'): ++G_count; break;
			case('C'): ++C_count; break;
			case(' '):	break;
			default:
								free(result);
								return(calloc(1, sizeof(char)));
		}
	}
	sprintf(result, "A:%d C:%d G:%d T:%d", A_count, C_count, G_count, T_count);
	return (result);
}
