#ifndef _ADHESIVE_STACK_H_
#define _ADHESIVE_STACK_H_

#include <stdint.h>

typedef struct {
    uint64_t capacity;
    uint64_t len;
    void **_data;
} adhesive_stack;

#define ADHESIVE_STACK_DEFAULT_CAP 16

adhesive_stack *adhesive_stack_new(void);
void adhesive_stack_free(adhesive_stack *stack);

void adhesive_stack_push(adhesive_stack *stack, void *data);
adhesive_stack *adhesive_stack_pop(adhesive_stack *stack);

#endif // _ADHESIVE_STACK_H_
