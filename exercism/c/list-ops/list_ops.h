#ifndef LIST_OPS_H
#define LIST_OPS_H

#include <stdlib.h>
#include <stdbool.h>

typedef int list_element_t;
typedef list_element_t (*folder)(list_element_t, list_element_t);

typedef struct {
   size_t length;
   list_element_t elements[];
} list_t;

list_t *new_list(size_t length, list_element_t elements[]);

list_t *append_list(list_t *list1, list_t *list2);

list_t *filter_list(list_t *list, bool (*filter)(list_element_t));

size_t length_list(list_t *list);

list_t *map_list(list_t *list, list_element_t (*map)(list_element_t));

list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t));

list_element_t foldr_list(list_t *list, list_element_t initial, folder Folder);

list_t *reverse_list(list_t *list);

void delete_list(list_t *list);

#endif
