#include <stddef.h>
#include "./land_perimeter.c"

int main() {
	const char arr[5][5] = {
		{'X', 'O', 'O', 'X', 'O'},
		{'X', 'O', 'O', 'X', 'O'},
		{'O', 'O', 'O', 'X', 'O'},
		{'X', 'X', 'O', 'X', 'O'},
		{'O', 'X', 'O', 'O', 'O'}
	};
	char res[100] ;
	land_perimeter(5, 5, arr, res);
	printf("%s\n", res);
}
