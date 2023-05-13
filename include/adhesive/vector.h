#ifndef _ADHESIVE_VECTOR_H_
#define _ADHESIVE_VECTOR_H_

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define AD_VECTOR_OF(TYPE, NAME)                                               \
    typedef struct {                                                           \
        TYPE *data;                                                            \
        size_t length;                                                         \
        size_t capacity;                                                       \
    } ad_vector_##NAME;                                                        \
                                                                               \
    ad_vector_##NAME *ad_vector_##NAME##_new(void) {                           \
        ad_vector_##NAME *vec = malloc(sizeof(ad_vector_##NAME));              \
        vec->length = 0;                                                       \
        vec->capacity = 16;                                                    \
        vec->data = malloc(sizeof(TYPE) * vec->capacity);                      \
        return vec;                                                            \
    }                                                                          \
                                                                               \
    void ad_vector_##NAME##_push_back(ad_vector_##NAME *vec, TYPE data) {      \
        if (vec->length + 1 == vec->capacity) {                                \
            printf("resize: %ld -> %ld\n", vec->capacity, vec->capacity * 2);  \
            vec->capacity *= 2;                                                \
            vec->data =                                                        \
                realloc(vec->data, vec->capacity * sizeof(ad_vector_##NAME));  \
        }                                                                      \
        vec->data[vec->length++] = data;                                       \
    }

AD_VECTOR_OF(int8_t, i8);
AD_VECTOR_OF(uint8_t, u8);

AD_VECTOR_OF(int16_t, i16);
AD_VECTOR_OF(uint16_t, u16);

AD_VECTOR_OF(int32_t, i32);
AD_VECTOR_OF(uint32_t, u32);

AD_VECTOR_OF(int64_t, i64);
AD_VECTOR_OF(uint64_t, u64);

AD_VECTOR_OF(void *, void);

#endif // _ADHESIVE_VECTOR_H_
