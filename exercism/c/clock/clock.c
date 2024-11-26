#include "clock.h"

#define ZERO_ASCII 48

clock_t clock_create(int hour, int minute) {

	while (minute < 0) minute += 60, --hour;
	while (minute >= 60) minute -= 60, ++hour;

	while (hour < 0)  hour += 24;
	while (hour >= 24) hour -= 24;

	clock_t clock = { .text = 0 };
	sscanf(clock.text, "%d:%d", &hour, &minute);
	return (clock);
}

clock_t clock_add(clock_t clock, int minute_add) {
	int hours = 
		(((int)clock.text[0] - ZERO_ASCII) * 10) +
		((int)clock.text[1] - ZERO_ASCII);
	int minutes = 
		(((int)clock.text[3] - ZERO_ASCII) * 10) +
		((int)clock.text[4] - ZERO_ASCII);

	minutes += minute_add;
	return (clock_create(hours, minutes));
}

clock_t clock_subtract(clock_t clock, int minute_subtract) {
	int hours = 
		(((int)clock.text[0] - ZERO_ASCII) * 10) +
		((int)clock.text[1] - ZERO_ASCII);
	int minutes = 
		(((int)clock.text[3] - ZERO_ASCII) * 10) +
		((int)clock.text[4] - ZERO_ASCII);

	minutes -= minute_subtract;
	return (clock_create(hours, minutes));
}

bool clock_is_equal(clock_t a, clock_t b) {
	for (int i = 0; i < MAX_STR_LEN; ++i)
		if (a.text[i] != b.text[i]) return (false);

	return (true);
}
