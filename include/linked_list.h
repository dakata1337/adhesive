#ifndef _ADHESIVE_LINKED_LIST_H_
#define _ADHESIVE_LINKED_LIST_H_

#include <stdint.h>

typedef struct adhesive_linked_list_elem adhesive_linked_list_elem;
struct adhesive_linked_list_elem {
    adhesive_linked_list_elem *next;
    adhesive_linked_list_elem *prev;
    void *data;
};

typedef struct {
    adhesive_linked_list_elem *head;
    adhesive_linked_list_elem *tail;
    uint64_t len;
} adhesive_linked_list;

adhesive_linked_list *adhesive_linked_list_new(void);
void adhesive_linked_list_free(adhesive_linked_list *list,
                               void(callback)(void *));

void adhesive_linked_list_pushback(adhesive_linked_list *list, void *data);
void adhesive_linked_list_insert_at(adhesive_linked_list *list, void *data,
                                    uint64_t idx);

void *adhesive_linked_list_remove_at(adhesive_linked_list *list, uint64_t idx);
void *adhesive_linked_list_pop(adhesive_linked_list *list);

#endif // _ADHESIVE_LINKED_LIST_H_
