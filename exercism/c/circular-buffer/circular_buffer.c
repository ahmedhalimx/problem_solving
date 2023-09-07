#include "circular_buffer.h"
#include <stdlib.h>

int16_t write(circular_buffer_t *cbuf, buffer_value_t val) {
    if (cbuf->end == (cbuf->values + (cbuf->length - 1))) {
        cbuf->end = cbuf->values;
        if (cbuf->end == NULL) {
            *(cbuf->end) = val;
            return (EXIT_SUCCESS);
        } else {
            return (EXIT_FAILURE);
        }
    }

    if ((cbuf->end + 1) != NULL) {
        *(cbuf->end) = val;
        return (EXIT_SUCCESS);
    } else {
        return (EXIT_FAILURE);
    }
}

int16_t overwrite(circular_buffer_t *cbuf, buffer_value_t val) {
    if (cbuf->end == (cbuf->values + (cbuf->length - 1))) {
        cbuf->end = cbuf->values;
        *(cbuf->end) = val;
        return (EXIT_SUCCESS);
    } else {
        ++cbuf->end;
        *(cbuf->end) = val;
        return (EXIT_SUCCESS);
    }
    return (EXIT_FAILURE);
}

int16_t read(circular_buffer_t *cbuf, buffer_value_t *val) {
    if (cbuf->start == (cbuf->values + (cbuf->length - 1))
            && cbuf->start != cbuf->end) {
        cbuf->start = cbuf->values;
        *val = *cbuf->start;
        return (EXIT_SUCCESS);
    }

    if (cbuf->start != cbuf->end) {
        ++cbuf->start;
        *val = *cbuf->start;
        return (EXIT_SUCCESS);
    }
    return (EXIT_FAILURE);
}

void delete_buffer(circular_buffer_t *cbuf) {
    int i;

    for (i = cbuf->length - 1; i >= 0; --i){
        free(cbuf->values + i);
    }
    cbuf->values = cbuf->start = cbuf->end = NULL;
}

//void write_values_to_buffer(values_length, values, false, buffer);

void write_values_to_buffer(size_t length, buffer_value_t values[], 
        bool overwrite, circular_buffer_t cbuf) {

}

void read_values_from_buffer(size_t length, buffer_value_t values[],
        circular_buffer_t cbuf) {

}

circular_buffer_t new_circular_buffer(size_t capacity) {

}
