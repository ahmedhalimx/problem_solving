#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <asm-generic/errno.h>
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <stdlib.h>

typedef uint16_t buffer_value_t;

typedef struct circular_buffer_s {
    size_t capacity;
		size_t size;
		bool isEmpty;
    buffer_value_t *buffer_data;
		buffer_value_t *read_ptr;
		buffer_value_t *write_ptr;
} circular_buffer_t;

int16_t read(circular_buffer_t *cbuf, buffer_value_t *read_val);
int16_t write(circular_buffer_t *cbuf, buffer_value_t bufval);
int16_t overwrite(circular_buffer_t *cbuf, buffer_value_t bufval);
circular_buffer_t* new_circular_buffer(uint16_t capacity);
void delete_buffer(circular_buffer_t *cbuf);
void clear_buffer(circular_buffer_t *cbuf);
void make_it_writable(buffer_value_t *value);

#endif
