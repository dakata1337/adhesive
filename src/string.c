#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "adhesive/math.h"
#include "adhesive/string.h"

ad_string *ad_string_with_capaicty(uint64_t cap) {
    ad_string *new_str = malloc(sizeof(ad_string));

    new_str->len = 0;
    new_str->cap = u64_next_pow(cap);
    new_str->str = malloc(cap);

    return new_str;
}

ad_string *ad_string_new(void) {
    return ad_string_with_capaicty(STRING_DEFAULT_CAPACITY);
}

ad_string *ad_string_from(char *data) {
    uint64_t len = strlen(data);
    ad_string *new_str = ad_string_with_capaicty(len + 1);

    memcpy(new_str->str, data, len + 1);
    new_str->len = len;
    return new_str;
}

void ad_string_free(ad_string *str) {
    free(str->str);
    free(str);
}

void string_grow_to_fit(ad_string *str, uint64_t size) {
    uint64_t new_cap = u64_next_pow(size);
    if (str->cap > new_cap) {
        return;
    }
    str->cap = new_cap;
    str->str = realloc(str->str, str->cap);
}

void ad_string_append_cstr(ad_string *str, const char *const data) {
    uint64_t len = strlen(data);
    if (len == 0)
        return;

    uint64_t new_len = str->len + len;
    string_grow_to_fit(str, new_len + 1);

    memcpy(str->str + str->len, data, len);
    assert(str->str[new_len - 1] != '\0');

    str->str[new_len] = '\0';
    str->len = new_len;
}

void ad_string_append(ad_string *dest, const ad_string *const src) {
    uint64_t new_len = dest->len + src->len;
    string_grow_to_fit(dest, new_len + 1);

    memcpy(dest->str + dest->len, src->str, src->len);
    dest->str[new_len] = '\0';
    dest->len = new_len;
}

inline ad_string *ad_string_clone(const ad_string *const str) {
    return ad_string_from(str->str);
}
