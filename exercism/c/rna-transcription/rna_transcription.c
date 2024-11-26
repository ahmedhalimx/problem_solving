#include "rna_transcription.h"

char *to_rna(const char *dna) {
	const int length = strlen(dna);
	char *rna = NULL;

	if (length == 0) 
		return (calloc(1, sizeof(char)));
	else
		rna = calloc(length + 1, sizeof(char));

	for (int i = 0; i < length; ++i) {
		switch (dna[i]) 
		{
			case('A'): rna[i] = 'U'; break;
			case('T'): rna[i] = 'A'; break;
			case('C'): rna[i] = 'G'; break;
			case('G'): rna[i] = 'C'; break;
		}
	}
	rna[length] = '\0';
	return (rna);
}
