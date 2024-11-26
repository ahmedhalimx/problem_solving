#include "resistor_color_duo.h"

uint16_t color_code(resistor_band_t *resistor) {
	return (10 * resistor[0] + resistor[1]);
}
