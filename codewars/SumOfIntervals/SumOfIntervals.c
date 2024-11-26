#include <stdio.h>
#include <stdlib.h>

typedef struct interval {
    int first;
    int second;
} interval_t;

int cmpfunc(const void *arg1, const void *arg2)
{
	interval_t a = *(const interval_t *)(arg1);
	interval_t b = *(const interval_t *)(arg2);
	if (b.first < a.first) return (1);
	else if (b.first > a.first) return (-1);
	return (b.second < a.second)? -1 : 1;
}

int sum_intervals(const interval_t *v, size_t n)
{
	long long result = 0;

	qsort((void *)v, n, sizeof(interval_t), cmpfunc);
	result = v[0].second - v[0].first;
	for (int i = 1; i < n; ++i) {
		if (v[i].first < v[i - 1].second) {
			if (!(v[i].second < v[i - 1].second)) {
				result += v[i - 1].second - v[i].second;
			}
			continue;
		}
		result += v[i].second - v[i].first;
	}
	return result;
}

int main(int argc, char **argv)
{
	const interval_t intervals[] = {
		{1, 5},
		{10, 20},
		{1, 6},
		{16, 19},
		{5, 11}	
	};
	const int SIZE = 5;

	int r = sum_intervals(intervals, SIZE);
	for (int i = 0; i < SIZE; ++i) {
		printf("at (%d) -> [ %d, %d]\n",
			i, intervals[i].first, intervals[i].second);
	}
	printf("result <- %d\n", r);
	return (EXIT_SUCCESS);
}
