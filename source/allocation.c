#include "allocation.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct cmt_allocation *cmt_allocation_create(
    const char *file,
    const char *function,
    const char *method,
    size_t line,
    size_t size,
    void *address
) {
    struct cmt_allocation *allocation = malloc(sizeof *allocation);
    if (allocation) {
        allocation->file = file;
        allocation->function = function;
        allocation->method = method;
        allocation->line = line;
        allocation->size = size;
        allocation->address = address;
    }

    return allocation;
}

void cmt_allocation_delete(struct cmt_allocation **allocation) {
    assert(allocation != NULL);
    assert(*allocation != NULL);
    free(*allocation);
    *allocation = NULL;
}

void cmt_allocation_print(struct cmt_allocation *allocation) {
    assert(allocation != NULL);
    printf(
        "allocation { file: %s, function: %s, method: %s, line: %lu, size: %lu, address: %p }\n",
        allocation->file,
        allocation->function,
        allocation->method,
        allocation->line,
        allocation->size,
        allocation->address
   );
}
