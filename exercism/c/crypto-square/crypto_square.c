#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "crypto_square.h"

#define ASSERT_INPUT(IN) if (!IN || (*IN) == '\0') \
                         return calloc(1, sizeof(char));

#define PERFORM_PADDING(t, d, c) for (int i = d - c; i != 0; --i) strcat(t, " ");

int get_rect_dimensions(char *txt, int *row, int *col)
{
   int len = strlen(txt);

   (*col) = ceil(sqrt(len));
   for (int i = 1; i <= (*col); ++i) {
      if (len <= i * (*col)) {
         (*row) = i;
         break;
      }
   }

   if ((*row) == 0)
      (*row) = (*col);

   return ((*row) * (*col));
}

char *strntrim(const char *src, int len)
{
   int idx = 0;
   char *res = calloc(len + 1, sizeof(char));

   for (int i = 0; i < len; ++i) {
      if (!isalnum(src[i])) continue;
      res[idx] = src[i];
      ++idx;
   }

   res = realloc(res, sizeof(char) * (idx + 1));
   res[idx] = '\0';

   return res;
}

void fill_square_code(char **rect, char *msg, int row, int col)
{
   for (int i = 0; i < row; ++i) {
      rect[i] = calloc(col + 1, sizeof(char));
      rect[i][col] = '\0';
      strncpy(rect[i], msg + (i * col), col);
   }
}

char *get_encrypted_message(char **rect, int row, int col)
{
   char *r = calloc((row * col) * 2, sizeof(char));
   int idx = 0;
   
   for (int i = 0; i < col; ++i) {
      for (int j = 0; j < row; ++j) {
         r[idx] = rect[j][i];
         ++idx;
      }
      if (i != col - 1) {
         r[idx] = ' ';
         ++idx;
      }
   }
   r = realloc(r, (idx + 1) * sizeof(char));
   r[idx] = '\0';
   return r;
}

char *strnlwr(const char *s, int len)
{
   char *r = calloc(len + 1, sizeof(char));

   for (int i = 0; i < len; ++i) {
      if (isalpha(s[i]))
         r[i] = tolower(s[i]);
      else
         r[i] = s[i];
   }

   return r;
}

char *normalize(char *plaintxt, int len)
{
   char *lowercase_txt = NULL;
   char *normalized_txt = NULL;
   
   lowercase_txt = strnlwr(plaintxt, len);
   normalized_txt = strntrim(lowercase_txt, len);
   
   free(lowercase_txt);
   return normalized_txt;
}

char *ciphertext(const char *input)
{
   ASSERT_INPUT(input);

   int col = 0, row = 0, len = 0;
   char *normalized_txt = NULL;  // all lowercase + trimmed text
   char *cipher = NULL;          // encrypted text
   char *text = NULL;            // a copy of the parameter @input
   
   // copy @input to @text
   len = strlen(input);
   text = calloc(len + 1, sizeof(char));
   strncpy(text, input, len);
   
   // return the normailzed version of @text
   normalized_txt = normalize(text, len);
   len = strlen(normalized_txt);

   // get the square code row and column val, return the
   // closest len to the actual @normalized_text len to
   // perform a square or a rectangle matrix
   int closest_len = get_rect_dimensions(normalized_txt, &row, &col);
   
   normalized_txt = realloc(normalized_txt, (closest_len + 1) * sizeof(char));
   normalized_txt[closest_len] = '\0';

   // pad @normalized_text with spaces if needed
   if (closest_len != len)
      PERFORM_PADDING(normalized_txt, (row * col), len);

   // create @square_code matrix and fill it with the @normalized_text
   char *square_code[row];
   fill_square_code(square_code, normalized_txt, row, col);
   
   // returns the square code encrypted message
   cipher = get_encrypted_message(square_code, row, col);
   
   // free unneeded memeory allocations
   free(text);
   free(normalized_txt);
   for (int i = 0; i < row; ++i)
      free(square_code[i]);
   
   return cipher;
}

