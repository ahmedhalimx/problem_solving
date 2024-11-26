#include "darts.h"
#define OUTTER_RADIUS (10)
#define MIDDLE_RADIUS (5)
#define INNER_RADIUS (1)

/**
 * score - computes the score based on the dart's landing position
 *
 * landing_position: dart's position on the target
 *
 * return: If the dart lands in the inner circle of the target, return (10)
 * 				else If it lands in the middle circle of the target, return (5)
 * 				else if it lands in the outer circle of the target, return (1)
 * 				else return (0).
 */

uint8_t score(coordinate_t landing_position) {
	const double radius = hypot(landing_position.x, landing_position.y);

	if (radius >= OUTTER_RADIUS) return (0);
	if (radius >= MIDDLE_RADIUS) return (5);
	return ((radius >= INNER_RADIUS) ? 5 : 10);
}
