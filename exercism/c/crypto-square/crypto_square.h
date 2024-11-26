#ifndef CRYPTO_SQUARE_H
#define CRYPTO_SQUARE_H

int get_rect_dimensions(char *txt, int *row, int *col);
char *strntrim(const char *src, int len);
void fill_square_code(char **rect, char *msg, int row, int col);
char *get_encrypted_message(char **rect, int row, int col);
char *normalize(char *plaintxt, int len);
char *strnlwr(const char *s, int len);
char *ciphertext(const char *input);

#endif
