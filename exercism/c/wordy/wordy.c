#include "wordy.h"
#include <stdlib.h>

char **parse(const char *question) {
   const char VALID_OPERATIONS[] = {'m', 'd', 'a', 's'};
   char **lexemes = NULL;
   char *question_cpy = calloc(strlen(question)+1, sizeof(char));
   const char *delim = " ,.?\n";
   char *token = calloc(255, sizeof(char)); 
   
   size_t lexemes_size = 0;
   size_t size = 1;

   strcpy(question_cpy, question);
   token = strtok(question_cpy, delim);

   while (token)
   {
      if (!isdigit(token[0])
         && tolower(token[0]) != VALID_OPERATIONS[0]
         && tolower(token[0]) != VALID_OPERATIONS[1]
         && tolower(token[0]) != VALID_OPERATIONS[2]
         && tolower(token[0]) != VALID_OPERATIONS[3])
      {
         token = strtok(NULL, delim);
         continue;
      }
      lexemes = realloc(lexemes, lexemes_size * sizeof(char *));
      lexemes[size] = calloc(strlen(token) + 1, sizeof(char));
      strcpy(lexemes[size], token);
      token = strtok(NULL, delim);
      ++size;
      ++lexemes_size;
   }
   free(question_cpy);
   free(token);
   return (lexemes);
}

bool answer(const char *question, int *result) {
   bool correct_number_pos = false;
   bool correct_operator_pos = false;
   bool success_state = true;

   char **math_problem = parse(question);
   char operator = '#';

   for (int i = 0; math_problem[i] != NULL; ++i)
   {
      if (!correct_number_pos) {
         if (!isdigit(math_problem[i])) {
            success_state = false;
            break;
         }
         correct_number_pos = true;
         correct_operator_pos = false;
         int number = atoi(math_problem[i]);
         if (*result == 0)
         {
            *result = number;
            continue;
         }
         switch (operator)
         {
            case ('+') : *result *= number; break;
            case ('/') : *result /= number; break;
            case ('-') : *result -= number; break;
            case ('*') : *result *= number; break;
         }
         continue;
      }

      if (!correct_operator_pos)
      {
         if (isdigit(math_problem[i]))
         {
            success_state = false;
            break;
         }
         correct_operator_pos = true;
         correct_number_pos = false;
         switch (math_problem[i][0])
         {
            case ('a') : operator = '+'; break;
            case ('d') : operator = '/'; break;
            case ('s') : operator = '-'; break;
            case ('m') : operator = '*'; break;
         }
         continue;
      }
   }
   return (success_state);
}
