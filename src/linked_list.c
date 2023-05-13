#include <stdint.h>
#include <stdlib.h>

#include "adhesive/linked_list.h"

ad_linked_list *ad_linked_list_new(void (*free_func)(void *)) {
    ad_linked_list *list = malloc(sizeof(ad_linked_list));
    list->head = list->tail = NULL;
    list->free_func = free_func;
    list->len = 0;

    return list;
}

void ad_linked_list_free(ad_linked_list *list) {
    ad_linked_list_node *current, *next;

    for (current = list->head; current; current = next) {
        next = current->next;
        list->free_func(current->data);
        free(current);
    }

    free(list);
}

void ad_linked_list_pushback(ad_linked_list *list, void *data) {
    ad_linked_list_node *elem = malloc(sizeof(ad_linked_list_node));
    elem->prev = elem->next = NULL;
    elem->data = data;

    if (list->head == NULL) {
        list->head = list->tail = elem;
    } else {
        list->tail->next = elem;
        elem->prev = list->tail;
        list->tail = elem;
    }

    list->len += 1;
}

void ad_linked_list_insert_at(ad_linked_list *list, void *data, uint64_t idx) {
    if (list->len <= idx) {
        return;
    }

    ad_linked_list_node *elem = malloc(sizeof(ad_linked_list_node));
    elem->prev = elem->next = NULL;
    elem->data = data;

    uint64_t counter = 0;
    ad_linked_list_node *tmp;
    for (tmp = list->head; tmp; tmp = tmp->next, counter++) {
        if (counter == idx) {
            elem->prev = tmp->prev;
            elem->prev->next = elem;

            elem->next = tmp;
            tmp->prev = elem;
            return;
        }
    }
}

void *ad_linked_list_remove_at(ad_linked_list *list, uint64_t idx) {
    if (list->len <= idx) {
        return NULL;
    }

    uint64_t counter = 0;
    ad_linked_list_node *elem;
    for (elem = list->head; elem; elem = elem->next, counter++) {
        if (counter == idx) {
            void *data = elem->data;
            if (elem->prev)
                elem->prev->next = elem->next;
            if (elem->next)
                elem->next->prev = elem->prev;

            list->len -= 1;
            free(elem);
            return data;
        }
    }

    return NULL;
}

void *ad_linked_list_pop(ad_linked_list *list) {
    ad_linked_list_node *elem = list->tail;
    if (elem == NULL) {
        return NULL;
    }

    void *data = elem->data;
    if (elem->prev)
        elem->prev->next = NULL;
    list->tail = elem->prev;

    list->len -= 1;
    free(elem);
    return data;
}
