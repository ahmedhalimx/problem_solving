#define _GNU_SOURCE
#include <stdio.h>

const char *number_to_string(int number) {
    char *res = NULL;
    asprintf(&res, "%d", number);
    return (res);
}

int main(int argc, char **argv)
{
	printf("%s", number_to_string(100));
	return (0);
}
