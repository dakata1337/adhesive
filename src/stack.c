#include <stdint.h>
#include <stdlib.h>

#include "stack.h"

adhesive_stack *adhesive_stack_with_capacity(uint64_t capacity) {
    adhesive_stack *stack = malloc(sizeof(adhesive_stack));

    stack->_data = malloc(sizeof(void *) * capacity);
    stack->len = 0;
    stack->capacity = capacity;

    return stack;
}

adhesive_stack *adhesive_stack_new(void) {
    return adhesive_stack_with_capacity(ADHESIVE_STACK_DEFAULT_CAP);
}

void adhesive_stack_free(adhesive_stack *stack, void (*free_func)(void *)) {
    for (uint64_t i = 0; i < stack->len; i++) {
        free_func(stack->_data[i]);
    }
    free(stack->_data);
    free(stack);
}

void adhesive_stack_push(adhesive_stack *stack, void *data) {
    // If the stack is full, double the capacity
    if ((stack->len + 1) >= stack->capacity) {
        stack->capacity *= 2;
        stack->_data = realloc(stack->_data, sizeof(void *) * stack->capacity);
    }

    stack->_data[stack->len] = data;
    stack->len += 1;
}

void *adhesive_stack_pop(adhesive_stack *stack) {
    if (stack->len == 0) {
        return NULL;
    }

    stack->len -= 1;
    void *data = stack->_data[stack->len];
    return data;
}
