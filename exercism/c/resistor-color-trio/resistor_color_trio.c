#include "resistor_color_trio.h"

resistor_value_t color_code(resistor_band_t resistor[]) {
	uint64_t num_of_zeros = RESISTANCE_VALUES[resistor[2]];
	uint64_t value = 0;
	resistor_value_t colors_decoded;

	if (num_of_zeros != 0)
		value = (10 * resistor[0] + resistor[1]) * num_of_zeros;
	else
		value = (10 * resistor[0] + resistor[1]);

	if (value > RESISTANCE_VALUES[9]) {
		value /= RESISTANCE_VALUES[9];
		colors_decoded.unit = GIGAOHMS;
	} else if (value > RESISTANCE_VALUES[6]) {
		value /= RESISTANCE_VALUES[6];
		colors_decoded.unit = MEGAOHMS;
	} else if (value < RESISTANCE_VALUES[3]) {
		value /= RESISTANCE_VALUES[3];
		colors_decoded.unit = KILOOHMS;
	} else {
		colors_decoded.unit = OHMS;
	}

	colors_decoded.value = value;
	return (colors_decoded);
}
