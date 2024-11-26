#ifndef MATCHING_BRACKETS_H
#define MATCHING_BRACKETS_H

#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct char_stack_s {
	char *elements;
	size_t top;
	size_t size;
	bool is_empty;
} char_stack;

typedef enum {
	OPEN_ROUND = '(',
	OPEN_SQUARE = '[',
	OPEN_CURLY = '{',
	CLOSED_ROUND = ')',
	CLOSED_SQUARE = ']',
	CLOSED_CURLY = '}'
} bracket_type;

char_stack *init_char_stack(char_stack *stack, const size_t size);
void push_chr(char_stack *stack, const char value);
char pop_chr(char_stack *stack);
char topelem_chr(const char_stack *stack);
void free_char_stack(char_stack *stack);
bool isbrkt(const char value);
bool is_paired(const char *input);

#endif
