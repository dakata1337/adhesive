#ifndef _ADHESIVE_LINKED_LIST_H_
#define _ADHESIVE_LINKED_LIST_H_

#include <stdint.h>

typedef struct ad_linked_list_node ad_linked_list_node;
struct ad_linked_list_node {
    ad_linked_list_node *next;
    ad_linked_list_node *prev;
    void *data;
};

typedef struct {
    ad_linked_list_node *head;
    ad_linked_list_node *tail;
    uint64_t len;
    void (*free_func)(void *);
} ad_linked_list;

/**
 * Allocates a new linked list. Needs to be freed with
 * `ad_linked_list_free()`
 * @returns a new linked list
 */
ad_linked_list *ad_linked_list_new(void (*free_func)(void *));

/**
 * Frees the given linked list.
 * @param list the linked list to free
 * @param free_func a function that is called for each element in the list
 */
void ad_linked_list_free(ad_linked_list *list);

/**
 * Pushes an element to the end of the linked list.
 * @param list the linked list
 * @param data the data to push
 */
void ad_linked_list_pushback(ad_linked_list *list, void *data);

/**
 * Inserts an element at the given index.
 * @param list the linked list
 * @param data the data to insert
 * @param index the index to insert the data at
 */
void ad_linked_list_insert_at(ad_linked_list *list, void *data, uint64_t idx);

/**
 * Removes an element at the given index.
 * @param list the linked list
 * @param index the index of the element to remove
 * @returns the pointer to the removed element OR `NULL` if the list is `empty`
 * or index is `out of range`
 */
void *ad_linked_list_remove_at(ad_linked_list *list, uint64_t idx);

/**
 * Pops an element from the end of the linked list.
 * @param list the linked list
 * @returns the pointer to the removed element OR `NULL` if the list is `empty`
 */
void *ad_linked_list_pop(ad_linked_list *list);

#endif // _ADHESIVE_LINKED_LIST_H_
