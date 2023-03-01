#ifndef _ADHESIVE_VECTOR_H_
#define _ADHESIVE_VECTOR_H_

#include <stdint.h>
#include <stdlib.h>

typedef struct {
    void **_data;
} adhesive_vector;

adhesive_vector *adhesive_vector_new(void);
adhesive_vector *adhesive_vector_with_capacity(uint64_t);
void adhesive_vector_free(adhesive_vector *vector, void (*free_func)(void *));

void adhesive_vector_pushback(adhesive_vector *list, void *data);
void *adhesive_vector_pop(adhesive_vector *list);
void adhesive_vector_insert_at(adhesive_vector *list, void *data, uint64_t idx);
void *adhesive_vector_remove_at(adhesive_vector *list, uint64_t idx);

#define adhesive_vector_foreach(list, NAME)                                    \
    {                                                                          \
        fprintf(stderr, "todo: implement me %s:%d\n", __FILE__, __LINE__);     \
        exit(1);                                                               \
    }

#endif // _ADHESIVE_VECTOR_H_
