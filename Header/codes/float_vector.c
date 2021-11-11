#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct float_vector {
    int capacity;
    int size;
    float *data;
} FloatVector;


bool _FloatVector_isFull(const FloatVector *vec) {
    return vec->size == vec->capacity;
}



FloatVector *FloatVector_create(int capacity) {
    FloatVector *vec = (FloatVector*) calloc(1, sizeof(FloatVector));
    vec->size = 0;
    vec->capacity = capacity;
    vec->data = (float*) calloc(capacity, sizeof(float));

    return vec;
}

void FloatVector_destroy(FloatVector **vec_ref) {
    FloatVector *aux = *vec_ref;
    
    free(aux->data);
    free(aux);
    *vec_ref = NULL;
}

int FloatVector_size(const FloatVector *vec) {
    return vec->size;
}

int FloatVector_capacity(const FloatVector *vec) {
    return vec->capacity;
}

float FloatVector_at(const FloatVector *vec, int index) {
    if (index < 0 || index >= vec->size) {
        fprintf(stderr, "ERROR int 'at'\n");
        fprintf(stderr, "Index [%d] is out of bounds: [0, %d]\n", index, vec->size - 1);
        exit(EXIT_FAILURE);
    }
    
}

float FloatVector_get(const FloatVector *vec, int index) {
    return vec->data[index];
}

void FloatVector_append(FloatVector *vec, float val) {
    if (_FloatVector_isFull(vec)) {
        fprintf(stderr, "ERROR in 'append'\n");
        fprintf(stderr, "Vector is FULL\n");
        exit(EXIT_FAILURE);
    }

    vec->data[vec->size++] = val;
}

void FloatVector_remove(FloatVector *vec, int index) {
    if (index < vec->capacity){
        for (int i = index; i < vec->capacity ; i++) {
			vec->data[i] = vec->data[i + 1];
		}
		vec->size -= 1;
    }
}


void FloatVector_erase(FloatVector *vec) {
	
}
// void FloatVector_clone(FloatVector *vec);

void FloatVector_set(FloatVector *vec, int index, float val) {
    if (index < 0 || index >= vec->size) {
        fprintf(stderr, "ERROR int 'set'\n");
        fprintf(stderr, "Index [%d] is out of bounds: [0, %d]\n", index, vec->size - 1);
        exit(EXIT_FAILURE);
    }
}

void FloatVector_print(const FloatVector *vec) {
    puts("------------------------------");
    printf("Size: %d\n", vec->size);
    printf("Capacity: %d\n", vec->capacity);
    puts("---");

    for (int i = 0; i < vec->size; i++) {
        printf("[%d] = %f\n", i, vec->data[i]);
    }
    puts("------------------------------\n");
    
}