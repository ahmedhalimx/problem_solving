#ifndef SECRET_HANDSHAKE_H
#define SECRET_HANDSHAKE_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

size_t *decode_number(size_t number);
const char **commands(size_t number);

#endif
