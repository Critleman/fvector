#include "vector.h"
#include <stdio.h>

int main() {

  Vector chars = vcreate(sizeof(char));
  Vector ints = vcreate(sizeof(int));
  Vector strs = vcreate(sizeof(char*));

  char *str = "helloo world";
  for (int i = 0; i < 16; i++) {
    printf("\nindex: %i\n", i);

    char tempchar = 'a'+i;
    vpush(&chars, &tempchar);
    printf("char: %c | %lu | %zu | %zu\n", *(char*)vget(&chars, i), chars.length, chars.size, chars.datatype);

    vpush(&ints, &i);
    printf("ints: %i | %lu | %zu | %zu\n", *(int*)vget(&ints, i), ints.length, ints.size, ints.datatype);

    vpush(&strs, &str);
    printf("strs: %s | %lu | %zu | %zu\n", *(char**)vget(&strs, i), strs.length, strs.size, strs.datatype);

  }
  printf("\n\n");
  for (int i = 15; i >= 0; i--) {
    printf("\nindex: %i\n", i);

    printf("ints: %i | %lu | %zu | %zu\n", *(int*)vget(&ints, i), ints.length, ints.size, ints.datatype);
    vpop(&ints);

    printf("char: %c | %lu | %zu | %zu\n", *(char*)vget(&chars, i), chars.length, chars.size, chars.datatype);
    vpop(&chars);

    printf("strs: %s | %lu | %zu | %zu\n", *(char**)vget(&strs, i), strs.length, strs.size, strs.datatype);
    vpop(&strs);
  }

  vfree(&chars);
  vfree(&ints);
  vfree(&strs);
}
