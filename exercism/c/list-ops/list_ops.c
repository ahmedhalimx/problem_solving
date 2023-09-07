#include "list_ops.h"

list_t *new_list(size_t length, list_element_t elements[]) {
    int i;
    list_t *list = malloc(sizeof(list_t) + length * sizeof(list_element_t));
    list->length = length;

    for (i = 0; i < length; ++i)
        list->elements[i] = elements[i];

    return (list);
}

list_t *append_list(list_t *list1, list_t *list2) {
    int i, j;
    list_element_t *elements = calloc((list1->length + list2->length),
            sizeof(list_element_t));
    
    for (i = 0; i < list1->length; ++i)
        elements[i] = list1->elements[i];

    for (j = 0; j < list2->length; ++j, ++i)
        elements[i] = list2->elements[j];

    return (new_list(list1->length + list2->length, elements));
}

list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
    
}
