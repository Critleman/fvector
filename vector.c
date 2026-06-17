#include "vector.h"

Vector vcreate(size_t datatype) {
  Vector vector;
  vector.size = datatype*2;
  vector.data = malloc(vector.size);
  vector.length = 0;
  vector.datatype = datatype;
  return vector;
}

void vpush(Vector *vector, void *value) {
  size_t byteIndex = vector->length * vector->datatype;
  for (int i = 0; i < vector->datatype; i++) {
    vector->data[byteIndex + i] = ((uint8_t*)value)[i];
  };

  vector->length++;

  if (byteIndex == vector->size) {
    vector->size *= 2;
    vector->data = realloc(vector->data, vector->size);
//    printf("vector allocated from %zu to %zu\n", vector->size/2, vector->size);
  }
}

void vpop(Vector *vector) {
  vector->length--;
  size_t byteIndex = vector->length * vector->datatype;

  if (byteIndex == vector->size/2) {
    vector->size /= 2;
    vector->data = realloc(vector->data, vector->size);
//    printf("vector deallocated from %zu to %zu\n", vector->size*2, vector->size);
  }
}

void vreset(Vector *vector) {
  vector->length = 0;
}
void vfree(Vector *vector) {
  free(vector->data);
  vector->data = NULL;
  vector->datatype = 0;
  vector->length = 0;
  vector->size = 0;
}

void vfreeElement(Vector *vector) {
  for (size_t i = 0; i < vector->length; i++) {
    free(vget(vector, i));
  }
}

uint8_t *vget(Vector *vector, size_t index) {
  return vector->data + vector->datatype * index;
}


