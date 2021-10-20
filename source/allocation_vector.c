#include "allocation_vector.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct cmt_allocation_vector *cmt_allocation_vector_create() {
    struct cmt_allocation_vector *allocation_vector = malloc(sizeof *allocation_vector);
    if (allocation_vector) {
        allocation_vector->size = 0;
        allocation_vector->data = NULL;
    }

    return allocation_vector;
}

void cmt_allocation_vector_delete(struct cmt_allocation_vector **allocation_vector) {
    assert(allocation_vector != NULL);
    assert(*allocation_vector != NULL);

    if ((*allocation_vector)->data != NULL) {
        free((*allocation_vector)->data);
    }

    free(*allocation_vector);
    *allocation_vector = NULL;
}

void cmt_allocation_vector_print(struct cmt_allocation_vector *allocation_vector) {
    assert(allocation_vector != NULL);
    printf(
        "allocation_vector { size: %lu, data: %p }\n",
        allocation_vector->size,
        allocation_vector->data
    );
}

void cmt_allocation_vector_push_back(struct cmt_allocation_vector *allocation_vector, struct cmt_allocation *allocation) {
    assert(allocation != NULL);
    assert(allocation_vector != NULL);
    allocation_vector->size += 1;
    allocation_vector->data = realloc(allocation_vector->data, allocation_vector->size * sizeof *allocation_vector->data);
    allocation_vector->data[allocation_vector->size - 1] = allocation;
}

size_t cmt_allocation_vector_find(struct cmt_allocation_vector *allocation_vector, void *address) {
    assert(allocation_vector != NULL);
    assert(allocation_vector->data != NULL);
    assert(address != NULL);

    for (size_t i = 0; i < allocation_vector->size; ++i) {
        if (allocation_vector->data[i]->address == address) {
            return i;
        }
    }

    return allocation_vector->size;
}

void cmt_allocation_vector_remove(struct cmt_allocation_vector *allocation_vector, size_t location) {
    assert(allocation_vector != NULL);
    assert(allocation_vector->data != NULL);

    cmt_allocation_delete(&allocation_vector->data[location]);
    for (size_t i = location; i < allocation_vector->size - 1; ++i) {
        allocation_vector->data[i] = allocation_vector->data[i + 1];
    }

    allocation_vector->data = realloc(allocation_vector->data, --allocation_vector->size * sizeof *allocation_vector->data);
}

void cmt_allocation_vector_clear(struct cmt_allocation_vector *allocation_vector) {
    assert(allocation_vector != NULL);
    assert(allocation_vector->data != NULL);

    for (size_t i = 0; i < allocation_vector->size; ++i) {
        cmt_allocation_delete(&allocation_vector->data[i]);
    }
    
    free(allocation_vector->data);
    allocation_vector->data = NULL;
    allocation_vector->size = 0;
}
