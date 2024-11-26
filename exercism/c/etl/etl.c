#include "etl.h"

int convert(const legacy_map *input, const size_t input_len, new_map **output) {
	size_t size = 0;
	new_map score_map[27] = 
	{
		{ 'a', 0 },  { 'b', 0 }, { 'c', 0 }, { 'd', 0 },
		{ 'e', 0 },  { 'f', 0 }, { 'g', 0 }, { 'h', 0 },
		{ 'i', 0 },  { 'j', 0 }, { 'k', 0 }, { 'l', 0 },
		{ 'm', 0 },  { 'n', 0 }, { 'o', 0 }, { 'p', 0 },
		{ 'q', 0 },  { 'r', 0 }, { 's', 0 }, { 't', 0 },
		{ 'u', 0 },  { 'v', 0 }, { 'w', 0 }, { 'x', 0 },
		{ 'y', 0 },  { 'z', 0 } 
	};

	for (size_t i = 0; i < input_len; ++i) {
		for (size_t j = 0; input[i].keys[j] != '\0'; ++j) {
			score_map[tolower(input[i].keys[j]) - 97].value = input[i].value;
			++size;
		}
	}
	*output = calloc(size + 1, sizeof(new_map));

	for (size_t i = 0, k = 0; i <= 26; ++i) {
		if (score_map[i].value == 0) continue;
		(*output)[k].key = score_map[i].key;
		(*output)[k].value = score_map[i].value;
		++k;
	}
	return (size);
}
