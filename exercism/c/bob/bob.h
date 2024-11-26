#ifndef BOB_H
#define BOB_H


#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

const char *hey_bob(char *greeting);
char *strtrim(char *str);
bool is_all_caps(char *str, size_t length);

#endif
