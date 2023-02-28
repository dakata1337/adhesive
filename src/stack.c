#include "stack.h"
#include <stdlib.h>

adhesive_stack *adhesive_stack_new(void) {
    adhesive_stack *stack = malloc(sizeof(adhesive_stack));

    stack->_data = malloc(sizeof(void *) * ADHESIVE_STACK_DEFAULT_CAP);
    stack->len = 0;
    stack->capacity = ADHESIVE_STACK_DEFAULT_CAP;

    return stack;
}
void adhesive_stack_free(adhesive_stack *stack, void (*free_func)(void *)) {
    for (uint64_t i = 0; i < stack->len; i++) {
        free_func(stack->_data[i]);
    }
    free(stack->_data);
    free(stack);
}

void adhesive_stack_push(adhesive_stack *stack, void *data) {
    if ((stack->len + 1) >= stack->capacity) {
        stack->capacity *= 2;
        stack->_data = realloc(stack->_data, sizeof(void *) * stack->capacity);
    }

    stack->_data[stack->len] = data;
    stack->len += 1;
}
adhesive_stack *adhesive_stack_pop(adhesive_stack *stack) {
    if (stack->len == 0) {
        return NULL;
    }

    adhesive_stack *top = stack->_data[stack->len - 1];
    stack->len -= 1;
    return top;
}
