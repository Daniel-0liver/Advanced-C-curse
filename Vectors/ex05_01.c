#include <stdio.h>
#include <stdlib.h>


double *vector_double(int  vd) {
    double *func_doub;
    func_doub = (double*) malloc(vd * sizeof(double));
    for (int i = 0; i < vd; i++)
    {
        func_doub[i] = i;
        printf("&func_doub[%d] = %p, func_doub[%d] = %f\n", i, &func_doub[i], i, func_doub[i]);
    }
    puts("");
    return func_doub;
}

int main() {
    int size_vector = 5;

    double *func = vector_double(size_vector);
    for (int i = 0; i < size_vector; i++)
    {
        printf("&func[%d] = %p, func[%d] = %f\n", i, &func[i], i, func[i]);
    }
    
    free(&func);
    func = NULL;
    return 0;
}