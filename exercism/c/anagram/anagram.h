#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <stddef.h>
#include <ctype.h>
#include <string.h> 
#include <stdbool.h>

#define MAX_STR_LEN 20

enum anagram_status { UNCHECKED = -1, NOT_ANAGRAM, IS_ANAGRAM };

typedef struct candidate {
   enum anagram_status is_anagram;
   const char *word;
} candidate_t;

typedef struct candidates {
   struct candidate *candidate;
   size_t count;
} candidates_t;

bool samechrcount(const char *s1, const char *s2);
void find_anagrams(const char *subject, candidates_t *candidates);

#endif
