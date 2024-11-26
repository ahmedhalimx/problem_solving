#include "resistor_color.h"

int color_code(resistor_band_t color) {
	return (color);
}

resistor_band_t *colors() {
	static resistor_band_t resistor_bands[10];

	for (resistor_band_t i = BLACK; i <= WHITE; ++i) {
		resistor_bands[i] = i;
	}
	return (resistor_bands);
}
