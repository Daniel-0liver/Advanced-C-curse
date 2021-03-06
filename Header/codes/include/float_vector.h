#ifndef FLOAT_VECTOR_H
#define FLOAT_VECTOR_H


typedef struct float_vector FloatVector;

FloatVector *FloatVector_create(int capacity);
void FloatVector_destroy(FloatVector **vec_ref);
int FloatVector_size(const FloatVector *vec);
int FloatVector_capacity(const FloatVector *vec);
void FloatVector_at(const FloatVector *vec, int index);
float FloatVector_get(const FloatVector *vec, int index);
void FloatVector_append(FloatVector *vec, float val);
void FloatVector_remove(FloatVector *vec, int index);
void FloatVector_erase(FloatVector *vec);
FloatVector *FloatVector_clone(FloatVector *vec);
void FloatVector_set(FloatVector *vec, int index);
void FloatVector_print(const FloatVector *vec);

#endif