#include "matching_brackets.h"

bool isbrkt(const char value) {
	switch (value)
	{
		case (OPEN_ROUND): case (OPEN_SQUARE):
		case (OPEN_CURLY): case (CLOSED_ROUND):
		case (CLOSED_SQUARE): case (CLOSED_CURLY):
			return (true);
		default:
			return (false);
	}
}

char_stack *init_char_stack(char_stack *stack, const size_t size) {
	stack->elements = calloc(size + 1, sizeof(char));
	stack->size = size;
	stack->top = 0;
	stack->is_empty = true;
	return (stack);
}

void push_chr(char_stack *stack, const char value) {
	if (stack->top >= stack->size) return;
	(stack->is_empty) ? stack->is_empty = false : ++stack->top;
	stack->elements[stack->top] = value;
}

char pop_chr(char_stack *stack) {
	char val = stack->elements[stack->top];

	stack->elements[stack->top] = '\0';
	(stack->top == 0) ? stack->is_empty = true : --stack->top;
	return (val);
}

char topelem_chr(const char_stack *stack) {
	return (stack->elements[stack->top]);
}

void free_char_stack(char_stack *stack) {
	free(stack->elements);
	free(stack);
}

bool is_paired(const char *input) {
	if (!input 
			|| input[0] == CLOSED_ROUND 
			|| input[0] == CLOSED_CURLY
			|| input[0] == CLOSED_SQUARE) return (false);

	char_stack *brkts_stk = calloc(1, sizeof(char_stack));
	bool stack_is_empty = false;

	brkts_stk = init_char_stack(brkts_stk, strlen(input));
	for (size_t i = 0; i < brkts_stk->size; ++i)
	{
		if (!isbrkt(input[i])) continue;
		bool correctly_enclosed = false;

		if (input[i] == OPEN_ROUND
				|| input[i] == OPEN_CURLY
				|| input[i] == OPEN_SQUARE)
		{
			push_chr(brkts_stk, input[i]);
			continue;
		}
		char last_opnbrkt = topelem_chr(brkts_stk);

		if ((input[i] == CLOSED_ROUND && last_opnbrkt == OPEN_ROUND)
				|| (input[i] == CLOSED_CURLY && last_opnbrkt == OPEN_CURLY)
				|| (input[i] == CLOSED_SQUARE && last_opnbrkt == OPEN_SQUARE))
		{
			correctly_enclosed = true;
		}

		if (!correctly_enclosed) {
			free_char_stack(brkts_stk);
			return (false);
		}
		pop_chr(brkts_stk);
	}
	stack_is_empty = brkts_stk->is_empty;
	free_char_stack(brkts_stk);
	return (stack_is_empty);
}
