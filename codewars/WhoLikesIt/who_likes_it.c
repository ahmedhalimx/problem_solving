#define _GNU_SOURCE
#include <stdio.h>


char *likes(size_t n, const char *const names[n]) {
	char *output = NULL;
	switch (n)
	{
		case (0):
			asprintf(&output, "%s", "no one likes this");
			break;
		case (1):
			asprintf(&output, "%s likes this", names[0]);
			break;
		case (2):
			asprintf(&output, "%s and %s like this", names[0], names[1]);
			break;
		case (3):
			asprintf(&output, "%s, %s and %s like this", names[0], names[1], names[2]);
			break;
		default:
			asprintf(&output, "%s, %s and %lu others like this", names[0], names[1], n - 2);
	}
	return (output);
}

int main(int argc, char **argv)
{
	return (0);
}
