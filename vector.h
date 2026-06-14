#pragma once
#include <stdlib.h>
#include <stdint.h>

typedef struct {
  size_t size;
  size_t datatype;
  size_t length;
  uint8_t *data;
} Vector;

Vector vcreate(size_t datatype);
void vpush(Vector *vector, void *value);
void vpop(Vector *vector);
void vfree(Vector *vector);
uint8_t *vget(Vector *vector, size_t index);
