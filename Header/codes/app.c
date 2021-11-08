#include <stdio.h>
#include "float_vector.h"

int main() {
    FloatVector *vec = create(10);

    destroy(&vec);

    printf("Its working");
    
    return 0;
}