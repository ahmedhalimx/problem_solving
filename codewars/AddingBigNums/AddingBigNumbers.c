#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long ull;

char *add(const char *a, const char *b)
{
	size_t len_a = strlen(a), len_b = strlen(b);
	int i = 0, j = 0;
	int carry = 0;

	if (len_b > len_a) {
		j = len_a;
	}
	else {
		i = len_a; j = len_b;
	}
	char *result = calloc(len_a + len_b, sizeof(char));
	for (i; i >= 0; --i) {
		int res = atoi()
	}
	return (result);
}

int main(int argc, char **argv)
{
	const char *one = "31";
	const char *two = "50";
	const char *res = add(one, two);

	printf("%s + %s = %s", one, two, res);
	printf("comparison <- %d", strcmp(res, "81"));

	
	return (EXIT_SUCCESS);
}
