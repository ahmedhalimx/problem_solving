#include "all_your_base.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH(A) (sizeof(A) / sizeof(A[0]))

bool is_valid_base(int16_t input_base, int16_t output_base)
{
   switch (input_base)
   {
      case (BIN): case (TRI):
      case (OCT): case (DEC):
      case (HEX): break;

      default: return (false);
   }

   switch (output_base)
   {
      case (BIN): case (TRI):
      case (OCT): case (DEC):
      case (HEX): break;

      default: return (false);
   }

   return (true);
}

size_t convert_to_bin(int8_t *output, int8_t *input, size_t input_len)
{
   int i = 0;

   --input_len;
   for (i = 0; i < input_len; ++i)
   {
      output[i] = input[i] 


   }
}

int8_t rebase(int8_t input_digits[], int16_t input_base,
	      int16_t output_base, size_t input_length)
{
   int8_t *output_digits = calloc(DIGITS_ARRAY_SIZE, sizeof(int8_t));
   size_t output_length = 0;

   if (!is_valid_base(input_base, output_base) || input_length == 0) {
      memset(input_digits, 0, input_length);
      free(output_digits);
      return (0);
   }

   if (input_base == output_base) {
      return (input_length);
   }

   switch (output_base)
   {
      case (BIN):
	 output_length = convert_to_bin(output_digits, input_digits, input_length);
	 break;
      case (TRI):
	 output_length = convert_to_tri(ouput, input); break;
      case (DEC):
	 output_length = convert_to_dec(output, input); break;
      case (OCT):
	 output_length = convert_to_oct(output, input); break;
      case (HEX):
	 output_length = convert_to_hex(output, input); break;
   }

   if (output_length != 0)
   {
      memset(input_digits, 0, input_length);
      memcpy(input_digits, output_digits, output_length);
      free(output_digits);
      return (output_length);
   }
}
