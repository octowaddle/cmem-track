#ifndef CMT_ALLOCATION_VECTOR_H
#define CMT_ALLOCATION_VECTOR_H

#include "allocation.h"

struct cmt_allocation_vector {
    size_t size;
    struct cmt_allocation **data;
};

struct cmt_allocation_vector *cmt_allocation_vector_create();

void cmt_allocation_vector_delete(struct cmt_allocation_vector **allocation_vector);

void cmt_allocation_vector_print(struct cmt_allocation_vector *allocation_vector);

void cmt_allocation_vector_push_back(struct cmt_allocation_vector *allocation_vector, struct cmt_allocation *allocation);

/// \brief Find an allocation in the allocation vector by its address.
/// \param allocation_vector A pointer to the allocation vector.
/// \param address The allocation address to find.
/// \return The position of the allocation in the allocation vector. If the
///         allocation was not found, the size of the allocation vector is
///         returned.
size_t cmt_allocation_vector_find(struct cmt_allocation_vector *allocation_vector, void *address);

void cmt_allocation_vector_remove(struct cmt_allocation_vector *allocation_vector, size_t location);

void cmt_allocation_vector_clear(struct cmt_allocation_vector *allocation_vector);

#endif
