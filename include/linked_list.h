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

/**
 * Allocates a new linked list. Needs to be freed with
 * `adhesive_linked_list_free()`
 * @returns a new linked list
 */
adhesive_linked_list *adhesive_linked_list_new(void);
/**
 * Frees the given linked list.
 * @param list the linked list to free
 * @param free_func a function that is called for each element in the list
 */
void adhesive_linked_list_free(adhesive_linked_list *list,
                               void (*free_func)(void *));

/**
 * Pushes an element to the end of the linked list.
 * @param list the linked list
 * @param data the data to push
 */
void adhesive_linked_list_pushback(adhesive_linked_list *list, void *data);
/**
 * Inserts an element at the given index.
 * @param list the linked list
 * @param data the data to insert
 * @param index the index to insert the data at
 */
void adhesive_linked_list_insert_at(adhesive_linked_list *list, void *data,
                                    uint64_t idx);

/**
 * Removes an element at the given index.
 * @param list the linked list
 * @param index the index of the element to remove
 * @returns the pointer to the removed element OR `NULL` if the list is `empty`
 * or index is `out of range`
 */
void *adhesive_linked_list_remove_at(adhesive_linked_list *list, uint64_t idx);
/**
 * Pops an element from the end of the linked list.
 * @param list the linked list
 * @returns the pointer to the removed element OR `NULL` if the list is `empty`
 */
void *adhesive_linked_list_pop(adhesive_linked_list *list);

/**
 * Iterates over the linked list.
 * Example:
 *   adhesive_linked_list_foreach(list, elem) {
 *       printf("%d\n", *(int *)elem->data);
 *   }
 */
#define adhesive_linked_list_foreach(list, NAME)                               \
    for (adhesive_linked_list_elem *NAME = list->head; NAME; NAME = NAME->next)

#endif // _ADHESIVE_LINKED_LIST_H_
