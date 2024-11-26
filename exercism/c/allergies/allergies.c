#include "allergies.h"

bool is_allergic_to(allergen_t allergy, int score) {
	allergen_list_t my_allergens = get_allergens(score);
	return (my_allergens.allergens[allergy]);
}

allergen_list_t get_allergens(int score) {
	const int allergen_scores[8] = { 1, 2, 4, 8, 16, 32, 64, 128 };
	allergen_list_t my_allergens = { .count = 0, .allergens = {false} };

	while (score != 0)
	{
		for (int i = 7; i >= 0;){
			//if (score > allergen_scores[i] || score == allergen_scores[i]) {
				score -= allergen_scores[i];
					my_allergens.allergens[i] = true;
					if (score == allergen_scores[i]) {
						++my_allergens.count;
						--i;
					}
				break;
			}
	}
	return (my_allergens);
}
