#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STACK_S {
	char *elements;
	int top;
	int size;
} STACK;


STACK *init(int size) {
	STACK *stk = malloc(sizeof(STACK));

	stk->elements = calloc(size, sizeof(char));
	stk->top = -1, stk->size = size;
	return stk;
}

void push(STACK *stk, char element) {
	if (stk->size != stk->top)
		stk->elements[++stk->top] = element;
}

char pop(STACK *stk) {
	if (stk->top >= 0) {
		char e = stk->elements[stk->top--];
		return e;
	} else {
		return 'x';
	}
}

void free_stk(STACK *stk) {
	free(stk->elements);
	free(stk);
}

char* removeStars(char* s) {
	int len = strlen(s);
	STACK *stk = init(len);

	for (int i = 0; i < len; ++i) {
		if (s[i] != '*') {
			push(stk, s[i]);
			continue;
		}
		pop(stk);
	}
	if (stk->top == -1) return "";
	char *result = calloc(stk->top + 2, sizeof(char));

	while (stk->top >= 0) {
		result[stk->top] = pop(stk);
	}
	free_stk(stk);
	return result;
}

int main(void) {
	char *s = "leet**cod*e";
	char *r = removeStars(s);
	printf("result: %s\n", r);
	free(r);
}
