#include "say.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char dtoc(const int d) {
   return (d + 30);
}

char *spell_out(const int h, const int t, const int o) {

   return "asdasd";
}



int say(int64_t input, char **ans)
{
   *ans = calloc(2000, sizeof(char));

   int idx = 0, excluded_digits = 0;
   int input_digits[13] = { 0 };

   for (int64_t i = input; i != 0; i /= 10) {
      int r = i % 10;
      input_digits[idx] = r;
      ++idx;
   }

   excluded_digits = idx % 3;
   for (int i = idx - 1; i > excluded_digits; i -= 3) {
      strcat(*ans, spell_out(input_digits[idx - 2], input_digits[idx - 1], input_digits[idx]));
   }

   *ans = realloc(*ans, sizeof(ans));
}
