#include <stdio.h>

#define LEG_A (m * m) - (n * n)
#define LEG_B 2 * m * n
#define HYPO_C (m * m) + (n * n)
#define FOLLOWS_PYTHAGOREAN_THEOREM (((LEG_A * LEG_A) + (LEG_B * LEG_B)) == (HYPO_C * HYPO_C))

/**
 * A = M^2 - N^2
 * B = 2MN
 * C = M^2 + N^2
 *
 * M > N > 0
 */
int main() {
	size_t number = 1000;
	size_t a = 0, b = 0, c = 0;

	// expected_triplets[] = { { 9, 40, 41 }, { 15, 36, 39 } };
	for (int n = 1; n < number; ++n) {
		int result = 0;
		for (int m = n + 1; m < number ; ++m) {
			a = LEG_A, b = LEG_B, c = HYPO_C;
			result = a + b + c;
			if (FOLLOWS_PYTHAGOREAN_THEOREM) {
				if (a > b)
					b = LEG_A, a = LEG_B;

				if (b > c)
					b = HYPO_C, c = LEG_B;
				if (result == number)
					printf("%lu + %lu + %lu = %lu\n", a, b, c, number);
			}
		}
	}
}
