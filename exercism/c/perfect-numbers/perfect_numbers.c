#include "perfect_numbers.h"

kind classify_number(int number)
{
   if (number <= 0)
      return ERROR;

   int sum = 0;
   
   for (int i = 1; i < number; ++i)
      if (number % i == 0)
         sum += i;

   if (sum > number)
      return ABUNDANT_NUMBER;
   else if (sum < number)
      return DEFICIENT_NUMBER;
   else
      return PERFECT_NUMBER;
}
