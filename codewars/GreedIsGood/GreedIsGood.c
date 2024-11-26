#include <stdio.h>
#include <stdlib.h>

int score(const int dice[5])
{
	const int SCORE_RULES[8] = {1000, 200, 300, 400, 500, 600, 100, 50};
	int total_appearance[6] = {0, 0, 0, 0, 0, 0};
	int score = 0;

	for (int i = 0; i < 5; ++i) total_appearance[dice[i] - 1] += 1;
	for (int i = 0; i < 6; ++i) {
		int throw_score = 0;
		if (total_appearance[i] >= 3) {
			throw_score = SCORE_RULES[i];
			score += (total_appearance[i] / 3) * throw_score;
			total_appearance[i] = total_appearance[i] % 3;
		}
		if ((i == 0 || i == 4) && total_appearance[i] != 0) {
			throw_score = (i == 0) ? SCORE_RULES[6] : SCORE_RULES[7];
			score += total_appearance[i] * throw_score;
		}
	}
	return (score);
}

int main(int argc, char **argv)
{
	int dice[5] = {3, 4, 1, 1, 1};
	int s = score(dice);

	printf("score => %d\n", s);
	return (EXIT_SUCCESS);
}
