#include "space_age.h"

#define	MERCURY_ORBITAL (0.2408467)
#define VENUS_ORBITAL (0.61519726)
#define SECONDS_IN_A_YEAR (31556952.0)
#define MARS_ORBITAL (1.8808158)
#define JUIPTER_ORBITAL (11.862615)
#define SATURN_ORBITAL (29.447498)
#define URANUS_ORBITAL (84.016846)
#define NEPTUNE_ORBITAL (164.79132)

float age(planet_t planet, int64_t seconds) {
	const float earth_year = seconds / SECONDS_IN_A_YEAR;

	switch(planet)
	{
		case (MERCURY):
			return (earth_year / MERCURY_ORBITAL);
		case (VENUS):
			return (earth_year / VENUS_ORBITAL);
		case (EARTH):
			return (earth_year);
		case (MARS):
			return (earth_year / MARS_ORBITAL);
		case (JUPITER):
			return (earth_year /  JUIPTER_ORBITAL);
		case (SATURN):
			return (earth_year / SATURN_ORBITAL);
		case (URANUS):
			return (earth_year / URANUS_ORBITAL);
		case (NEPTUNE):
			return (earth_year / NEPTUNE_ORBITAL);
		default:
			return (-1);
	}
}
