#include <stdio.h>


short knight(const char *p1, const char *p2)
{

}

int main(void)
{
	printf("pos(\"a1\", \"c1\"): %d, expected: 2\n", knight("a1", "c1"));
	printf("pos(\"a1\", \"f1\"): %d, expected: 3\n", knight("a1", "f1"));
	printf("pos(\"a1\", \"f3\"): %d, expected: 3\n", knight("a1", "f3"));
	printf("pos(\"a1\", \"f4\"): %d, expected: 4\n", knight("a1", "c1"));
	printf("pos(\"a1\", \"f7\"): %d, expected: 5\n", knight("a1", "c1"));
}
