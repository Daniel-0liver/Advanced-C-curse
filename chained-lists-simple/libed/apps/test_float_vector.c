#include <stdio.h>
#include "float_vector.h"
#include "mytime.h"

int main() {

    timer t1 = tic();

    FloatVector *vec = FloatVector_create(3);

    FloatVector_print(vec);

    FloatVector_append(vec, 0.1);
    FloatVector_append(vec, 1.0);
    FloatVector_append(vec, 2.0);

    FloatVector_print(vec);

    FloatVector *clone = FloatVector_clone(vec);

    FloatVector_print(clone);

    FloatVector_remove(vec, 0);

    FloatVector_print(vec);

    FloatVector_erase(vec);

    FloatVector_print(vec);

    FloatVector_destroy(&vec);

    timer t2 = tac();
    printf("Processing time: %f ms\n", comptime(t1, t2));
    
    return 0;
}