#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "linked_list.h"

adhesive_linked_list *adhesive_linked_list_new(void) {
    adhesive_linked_list *list = malloc(sizeof(adhesive_linked_list));
    assert(list != NULL && "malloc() failed");

    list->head = list->tail = NULL;
    list->len = 0;
    return list;
}

void adhesive_linked_list_free(adhesive_linked_list *list,
                               void(callback)(void *)) {
    assert(list != NULL);

    adhesive_linked_list_elem *current, *next;
    for (current = list->head; current; current = next) {
        next = current->next;
        callback(current->data);
        free(current);
    }

    free(list);
}

/* Insert functions */
void adhesive_linked_list_pushback(adhesive_linked_list *list, void *data) {
    assert(list != NULL);

    adhesive_linked_list_elem *elem = malloc(sizeof(adhesive_linked_list_elem));
    assert(list != NULL && "malloc() failed");

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

void adhesive_linked_list_insert_at(adhesive_linked_list *list, void *data,
                                    uint64_t idx) {
    assert(list != NULL);
    if (list->len <= idx) {
        return;
    }

    adhesive_linked_list_elem *elem = malloc(sizeof(adhesive_linked_list_elem));
    assert(list != NULL && "malloc() failed");

    elem->prev = elem->next = NULL;
    elem->data = data;

    uint64_t counter = 0;
    adhesive_linked_list_elem *tmp;
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

/* Remove functions */
void *adhesive_linked_list_remove_at(adhesive_linked_list *list, uint64_t idx) {
    assert(list != NULL);
    if (list->len <= idx) {
        return NULL;
    }

    uint64_t counter = 0;
    adhesive_linked_list_elem *elem;
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

void *adhesive_linked_list_pop(adhesive_linked_list *list) {
    assert(list != NULL);

    adhesive_linked_list_elem *elem = list->tail;
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
