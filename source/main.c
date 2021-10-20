#include "allocation.h"

#include <stdlib.h>

int main() {
    long *value = malloc(sizeof *value);

    struct cmt_allocation *allocation = cmt_allocation_create(
        NULL,
        NULL,
        NULL,
        0,
        4,
        0x23a1b323
    );
    
    cmt_allocation_print(allocation);
    cmt_allocation_delete(&allocation);
}
