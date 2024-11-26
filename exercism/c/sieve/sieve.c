#include "sieve.h"


uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
		if (limit == 0 || limit == 1) return (0);

		limit -= 2;
		bool *map_of_numbers = calloc(false, sizeof(bool) * (limit)), marking_occured = false;
		size_t p = 0;

    for (size_t i = 0; i <= limit && p < max_primes; ++i) {
        size_t number = i + 2;
        for (size_t j = number; (number * j) <= limit + 2 && p < max_primes; ++j) {
            size_t value = (number * j) - 2;

            if (map_of_numbers[value] == false) {
                map_of_numbers[value] = true;
                marking_occured = true;
            }
        }
        if (marking_occured == false) break;
        marking_occured = false;
        while (map_of_numbers[i + 1] == true && (i + 1) < limit) ++i;
    }

    for (size_t i = 0; i <= limit; ++i) {
			if (map_of_numbers[i] == false && p < max_primes) {
				primes[p] = i + 2;
				++p;
			}
    }
		free(map_of_numbers);
		return (p);
}
