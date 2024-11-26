#ifndef WORDY_H
#define WORDY_H

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool answer(const char *question, int *result);
char **parse(const char *question);

#endif
