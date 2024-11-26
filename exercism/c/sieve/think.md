```c
// N is the MAX number
void sieve_of_eratosthenes(size_t N) {
    bool map_of_numbers[998] = {false};
    bool marking_occured = false;

    for (int i = 0; i < N; ++i) {
        size_t rprsntd_number = i + 2, r = 0;
        for (int j = rprsntd_number; j < N; ++j) {
            r = rprsntd_number * j;
            if (map_of_numbers[r - 2] == false) {
                map_of_numbers[r - 2] = true;
                marking_occured = true;
            }
        }
        if (marking_occured == false) break;

        marking_occured = false;
        while (map_of_numbers[i + 1] == true)
            ++i;
    }

    for (int i = 0; i < limit; ++i) {
        if (isMarked[i] == false)
            printf("at [%d] which represents number %d is prime\n", i, i + 2);
    }
}
```
