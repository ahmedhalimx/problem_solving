#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <stddef.h>
#include <stdlib.h>

typedef int ll_data_t;

typedef struct list_node {
	struct list_node *prev, *next;
	ll_data_t data;
} list_node_t ;

typedef struct list {
	struct list_node *first, *last;
} list_t;

list_t *list_create();
void list_push(list_t *list, const ll_data_t item_data);
ll_data_t list_shift(list_t *list);
ll_data_t list_pop(list_t *list);
void list_unshift(list_t *list, const ll_data_t item_data);
void list_delete(list_t *list, const ll_data_t data);
size_t list_count(const list_t *list);
void list_destroy(list_t *list);

#endif
