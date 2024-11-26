#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct STACK_S {
	char *elements;
	int top;
	int size;
} STACK;


STACK *init(int size) {
	STACK *stk = malloc(sizeof(STACK));
	stk->elements = calloc(size, sizeof(char)), stk->top = -1, stk->size = size;
	return stk;
}

void push(STACK *stk, char element) {
	if (stk->size != stk->top)
		stk->elements[++stk->top] = element;
}

char pop(STACK *stk) {
	char x = '\0';
	if (stk->top >= 0)
		x = stk->elements[stk->top--];
	return x;
}

void free_stk(STACK *stk) {
	free(stk->elements), free(stk);
}

char *strtrm(char *s, int l) {
	int idx = 0;
	char *r = calloc(l + 1, sizeof(char));
	bool readspace = false;

	for (int i = 0; i < l; ++i) {
		if (s[i] != ' ') {
			r[idx++] = s[i];
			readspace = true;
			continue;
		}
		if (readspace) {
			r[idx++] = s[i];
			readspace = false;
		}
	}
	return r;
}

char* reverseWords(char* s)
{
	int slen = strlen(s);
	char *t = strtrm(s, slen);
	int len = strlen(t);
	STACK *stk = init(len);
	char *r = calloc(len + 1, sizeof(char));
	int idx = 0;

	for (int i = len - 1; i >= -1; --i) {
		if (t[i] != ' ' && i >= 0) {
			push(stk, t[i]);
			continue;
		}
		while (stk->top >= 0) {
			r[idx] = pop(stk);
			++idx;
		}
		r[idx++] = ' ';
	}
	printf("---reverse: '%s'\n", r);
	free(t);
	free_stk(stk);
	return r;
}


int main(void) {
	char *s = "   a good   example   ";
	int l = strlen(s);
	char *r = reverseWords(s);

	printf("input: '%s'\nresult:'%s'\n", s, r);
	free(r);
}
