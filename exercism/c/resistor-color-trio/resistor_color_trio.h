#ifndef RESISTOR_COLOR_TRIO_H
#define RESISTOR_COLOR_TRIO_H

#include <stdint.h>

static const uint64_t RESISTANCE_VALUES[] = 
{
	0, 10, (10 * 2),(10 * 3),
	(10 * 4), (10 * 5), (10 * 6),
	(10 * 7), (10 * 8), (10 * 9)
};

typedef enum {
	OHMS = 0,
	KILOOHMS = 3,
	MEGAOHMS = 6,
	GIGAOHMS = 9
} resistance_unit_t;

typedef enum {
	BLACK, BROWN, RED,
	ORANGE, YELLOW, GREEN,
	BLUE, VIOLET, GREY, WHITE
} resistor_band_t;

typedef struct resistor_value_s {
	uint16_t value;
	resistance_unit_t unit;
} resistor_value_t;

resistor_value_t color_code(resistor_band_t resistor[]);
#endif
