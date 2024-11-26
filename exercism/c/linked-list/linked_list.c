#include "linked_list.h"

list_t *list_create() {
  list_t *new_list = malloc(sizeof(list_t));

  new_list->first = new_list->last = NULL;
  return (new_list);
}

void list_push(list_t *list, const ll_data_t item_data) {
  list_node_t *new_node = malloc(sizeof(list_node_t));

  if (!list->first && !list->last) {
    list->first = list->last = new_node;
    new_node->next = new_node->prev = NULL;
  } else {
    new_node->prev = list->last;
    new_node->next = NULL;
    list->last->next = new_node;
    list->last = new_node;
  }
  new_node->data = item_data;
}

ll_data_t list_shift(list_t *list) {
  if (!list->first)
    return (0);
  list_node_t *popped_node = list->first;
  const ll_data_t item_data = list->first->data;

  if (list->first->next) {
    list->first = list->first->next;
    list->first->prev = NULL;
  } else {
    list->first = list->last = NULL;
  }
  free(popped_node);
  return (item_data);
}

ll_data_t list_pop(list_t *list) {
  if (!list->last)
    return (0);
  list_node_t *popped_node = list->last;
  const ll_data_t item_data = list->last->data;

  if (list->last->prev) {
    list->last = list->last->prev;
    list->last->next = NULL;
  } else {
    list->first = list->last = NULL;
  }
  free(popped_node);
  return (item_data);
}

void list_unshift(list_t *list, const ll_data_t item_data) {
  if (!list->first) {
    list_push(list, item_data);
    return;
  }
  list_node_t *new_node = malloc(sizeof(list_node_t));

  new_node->data = item_data;
  new_node->next = list->first;
  new_node->prev = NULL;
  list->first->prev = new_node;
  list->first = new_node;
}

void list_delete(list_t *list, const ll_data_t item_data) {
  list_node_t *itr = NULL;

  if (item_data == list->first->data) {
    list_shift(list);
    return;
  } else if (item_data == list->last->data) {
    list_pop(list);
    return;
  }

  for (itr = list->first->next; itr != NULL; itr = itr->next) {
    if (itr->data == item_data) {
      list_node_t *popped_node = itr;

      itr->next->prev = itr->prev;
      itr->prev->next = itr->next;
      free(popped_node);
      break;
    }
  }
}

size_t list_count(const list_t *list) {
  list_node_t *itr = NULL;
  size_t counter = 0;

  for (itr = list->first; itr != NULL; itr = itr->next)
    ++counter;
  return (counter);
}

void list_destroy(list_t *list) {
  if (!list)
    return;
  while (list->last != NULL)
    list_pop(list);
  free(list);
}
