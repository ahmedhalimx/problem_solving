#include "word_count.h"

/**
 * 									____________
 * 		sentence --->|count_words|---> {words}
 * 			 _______________|________________________
 *			|							 |												|
 *		parse		  check repeation			check MAX_WORD_COUNT
 *
 *	(parsing): 1. parse all word in lowercase.
 *						 2. separtors are all kind of whitespaces, and puncts,
 *						 		however, contractions are cosedired words.
 *						 	
 */
int count_words(const char *sentence, word_count_word_t *words) {
	/* Parsing */
	const char *DELIM = "\t\r\n .,:;!?\'\"";

}
