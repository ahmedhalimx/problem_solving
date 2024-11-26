#include "dnd_character.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ROLL_DICE() ((rand() % 6) + 1)

int ability(void)
{
   srand(time(NULL));

   int sum = 0, min = 7;
   int dice_rolls[4] = {
      ROLL_DICE(), ROLL_DICE(),
      ROLL_DICE(), ROLL_DICE()
   };

   for (int i = 0; i < 4; ++i) {
      sum += dice_rolls[i];
      if (dice_rolls[i] < min)
         min = dice_rolls[i];
   }

   return sum - min;
}

int modifier(int score)
{
   return floor((score - 10.0f) / 2.0f);
}

dnd_character_t make_dnd_character(void)
{
   dnd_character_t chrctr;

   chrctr.strength      = ability();
   chrctr.dexterity     = ability();
   chrctr.constitution  = ability();
   chrctr.intelligence  = ability();
   chrctr.wisdom        = ability();
   chrctr.charisma      = ability();
   chrctr.hitpoints     = 10 + modifier(chrctr.constitution);

   return chrctr;
}
