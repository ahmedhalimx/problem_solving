#include "circular_buffer.h"
#include <stdlib.h>

int16_t write(circular_buffer_t *cbuf, buffer_value_t bufval) {
	if (cbuf->size == cbuf->capacity) {
		errno = ENOBUFS;
		return (EXIT_FAILURE);
	}

	if (cbuf->size == 0) {
		*(cbuf->write_ptr) = bufval;
		++cbuf->size;
		return (EXIT_SUCCESS);
	}

	if (cbuf->size != cbuf->capacity) {
		if (cbuf->write_ptr == &(cbuf->buffer_data[cbuf->capacity - 1])) 
			cbuf->write_ptr= &(cbuf->buffer_data[0]);
		else
			++cbuf->write_ptr;
	}
	*(cbuf->write_ptr) = bufval;
	++cbuf->size;
	return (EXIT_SUCCESS);
}

int16_t overwrite(circular_buffer_t *cbuf, buffer_value_t bufval) {
	if (cbuf->size != cbuf->capacity) return (write(cbuf, bufval));
	if (cbuf->write_ptr == &(cbuf->buffer_data[cbuf->capacity - 1])) {
		if (cbuf->read_ptr == &(cbuf->buffer_data[0])) ++cbuf->read_ptr;
		cbuf->write_ptr = &(cbuf->buffer_data[0]);
		*(cbuf->write_ptr) = bufval;
} else {
		if ((cbuf->write_ptr + 1) == cbuf->read_ptr) {
			if (cbuf->read_ptr == &(cbuf->buffer_data[cbuf->capacity - 1]))
				cbuf->read_ptr = &(cbuf->buffer_data[0]);
			else
				++cbuf->read_ptr;
		}

		++cbuf->write_ptr;
		*(cbuf->write_ptr) = bufval;
	}
	return (EXIT_SUCCESS);
}

int16_t read(circular_buffer_t *cbuf, buffer_value_t *read_val) {
	if (cbuf->size == 0 || !cbuf) {
		errno = ENODATA;
		return (EXIT_FAILURE);
	}

	*(read_val) = *(cbuf->read_ptr);
	--cbuf->size;

	if (cbuf->read_ptr != cbuf->write_ptr) {
		if (cbuf->read_ptr == &(cbuf->buffer_data[cbuf->capacity - 1])) 
			cbuf->read_ptr = &(cbuf->buffer_data[0]);
		else
			++cbuf->read_ptr;
	}
	return (EXIT_SUCCESS);
}

void clear_buffer(circular_buffer_t *cbuf) {
	if (cbuf->buffer_data) free(cbuf->buffer_data);
	cbuf->read_ptr = cbuf->write_ptr = &(cbuf->buffer_data[0]);
	cbuf->size = 0;
}

void delete_buffer(circular_buffer_t *cbuf) {
	if (cbuf) free(cbuf);
}

circular_buffer_t* new_circular_buffer(uint16_t capacity) {
	circular_buffer_t *cbuf = malloc(sizeof(circular_buffer_t));

	cbuf->buffer_data = malloc(sizeof(buffer_value_t) * capacity);
	cbuf->write_ptr = cbuf->read_ptr = &(cbuf->buffer_data[0]);
	cbuf->capacity = capacity;
	cbuf->isEmpty = true;
	cbuf->size = 0;
	return (cbuf);
}
