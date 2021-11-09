#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct float_vector {
    int capacity;
    int size;
    float *data;
} FloatVector;

FloatVector *create(int capacity) {
    FloatVector *vec = (FloatVector*) calloc(1, sizeof(FloatVector));
    vec->size = 0;
    vec->capacity = capacity;
    vec->data = (float*) calloc(capacity, sizeof(float));

    return vec;
}

void destroy(FloatVector **vec_ref) {
    FloatVector *aux = *vec_ref;
    
    free(aux->data);
    free(aux);
    *vec_ref = NULL;
}

// int size(const FloatVector *vec);

// int capacity(const FloatVector *vec);

// float at(const FloatVector *vec, int index);

// float get(const FloatVector *vec, int index);

void append(FloatVector *vec, float val) {
    if (vec->size == vec->capacity) {
        fprintf(stderr, "ERROR in 'append'\n");
        fprintf(stderr, "Vector is FULL\n");
        exit(EXIT_FAILURE);
    }

    vec->data[vec->size++] = val;
}

// void set(FloatVector *vec, int index, float val);

void print(const FloatVector *vec) {
    puts("------------------------------");
    printf("Size: %d\n", vec->size);
    printf("Capacity: %d\n", vec->capacity);
    puts("---");

    for (int i = 0; i < vec->size; i++) {
        printf("[%d] = %f\n", i, vec->data[i]);
    }
    puts("------------------------------\n");
    
}