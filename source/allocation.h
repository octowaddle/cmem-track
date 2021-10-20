#ifndef CMT_ALLOCATION_H
#define CMT_ALLOCATION_H

#include <stddef.h>

struct cmt_allocation {
    const char *file;
    const char *function;
    const char *method;
    size_t line;
    size_t size;
    void *address;
};

struct cmt_allocation *cmt_allocation_create(
    const char *file,
    const char *function,
    const char *method,
    size_t line,
    size_t size,
    void *address
);

void cmt_allocation_delete(struct cmt_allocation **allocation);

void cmt_allocation_print(struct cmt_allocation *allocation);

#endif
