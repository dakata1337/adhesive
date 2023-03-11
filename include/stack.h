#ifndef _ADHESIVE_STACK_H_
#define _ADHESIVE_STACK_H_

#include <stdint.h>

typedef struct {
    uint64_t capacity;
    uint64_t len;
    void **_data;
} adhesive_stack;

#define ADHESIVE_STACK_DEFAULT_CAP 8

/**
 * Allocates a new adhesive stack on the heap with the specified capacity. Needs
 * to be freed by calling `adhesive_stack_free()`
 * @param capacity the starting capacity of the stack
 */
adhesive_stack *adhesive_stack_with_capacity(uint64_t capacity);

/**
 * Allocates a new adhesive stack on the heap. Needs to be freed by calling
 * `adhesive_stack_free()`
 */
adhesive_stack *adhesive_stack_new(void);

/**
 * Frees the given stack.
 * @param stack the stack to free
 * @param free_func a function that is called for each element in the stack
 */
void adhesive_stack_free(adhesive_stack *stack, void (*free_func)(void *));

/**
 * Pushes a new item onto the stack.
 * @param stack the stack to push onto
 * @param data a pointer to the value
 */
void adhesive_stack_push(adhesive_stack *stack, void *data);

/**
 * Pops the top item from the stack.
 * @param stack the stack from which to pop off
 * @returns the item, or `NULL` if the stack is empty
 */
void *adhesive_stack_pop(adhesive_stack *stack);

#endif // _ADHESIVE_STACK_H_
