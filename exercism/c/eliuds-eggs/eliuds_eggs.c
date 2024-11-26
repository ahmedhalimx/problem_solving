#include "eliuds_eggs.h"

ui egg_count(ui decimal_representation)
{
      ui egg_count_ = 0;

      //convert decimal digits to binary digits
      for (ui i = decimal_representation; i != 0; i /= 2) {
            if (i % 2 == 1)
                  ++egg_count_;
      }
   return __builtin_popcount(decimal_representation);
      //return egg_count_;
}
