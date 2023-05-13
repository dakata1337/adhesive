#ifndef _ADHESIVE_STRING_H_
#define _ADHESIVE_STRING_H_

#include <stdint.h>

#define STRING_DEFAULT_CAPACITY 32

typedef struct {
    char *str;
    uint64_t len;
    uint64_t cap;
} ad_string;

ad_string *ad_string_new(void);
ad_string *ad_string_with_capaicty(uint64_t cap);
ad_string *ad_string_from(char *data);
void ad_string_free(ad_string *str);

void ad_string_append_cstr(ad_string *str, const char *const data);
void ad_string_append(ad_string *dest, const ad_string *const src);
inline ad_string *ad_string_clone(const ad_string *const str);

#define ad_string_split(STR, DELIM, CALLBACK)                                  \
    {                                                                          \
        char *value, *_ptr, *_tofree;                                          \
        _tofree = _ptr = strdup(STR->str);                                     \
        while ((value = strsep(&_ptr, DELIM))) {                               \
            CALLBACK                                                           \
        }                                                                      \
        free(_tofree);                                                         \
    }

#endif // _ADHESIVE_STRING_H_
