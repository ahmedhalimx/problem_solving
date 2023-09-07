#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef uint16_t buffer_value_t;

typedef struct sasx {
    size_t length;
    buffer_value_t *values, *start, *end;
} circular_buffer_t;

int16_t read(circular_buffer_t *cbuf, buffer_value_t *bufvalue);

int16_t write(circular_buffer_t *cbuf, buffer_value_t bufval);
int16_t overwrite(circular_buffer_t *cbuf, buffer_value_t bufval);

void read_values_from_buffer(size_t length, buffer_value_t values[], circular_buffer_t cbuff);

void write_values_to_buffer(size_t length, buffer_value_t values[],
        bool overwrite, circular_buffer_t cbuff);

circular_buffer_t new_circular_buffer(size_t capacity);
void delete_buffer(circular_buffer_t *cbuf);

#endif
