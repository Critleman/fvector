#include "vector.h"
#include <string.h>
#include <stdio.h>

int main() {

  Vector chars = vcreate(sizeof(char));
  Vector ints = vcreate(sizeof(int));
  Vector strs = vcreate(sizeof(char*));

  for (int i = 0; i < 16; i++) {
    char *str = malloc(20);
    snprintf(str, 20, "%s%i", "hello world", i);
    printf("\nindex: %i\n", i);

    char tempchar = 'a'+i;
    vpush(&chars, &tempchar);
    printf("char: %c | %lu | %zu | %zu\n", *(char*)vget(&chars, i), chars.length, chars.size, chars.datatype);

    vpush(&ints, &i);
    printf("ints: %i | %lu | %zu | %zu\n", *(int*)vget(&ints, i), ints.length, ints.size, ints.datatype);

    vpush(&strs, &str);
    printf("strs: %s | %lu | %zu | %zu\n", *(char**)vget(&strs, i), strs.length, strs.size, strs.datatype);

  }
  printf("n\n");
  vreset(&ints); // set length to 0
  int nn = 99;
  vpush(&ints, &nn); // 99 should be in the first index
  for (int i = 15; i >= 0; i--) {
    printf("\nindex: %i\n", i);
    
    printf("ints: %i | %lu | %zu | %zu\n", *(int*)vget(&ints, i), ints.length, ints.size, ints.datatype);
    vpop(&ints);

    printf("char: %c | %lu | %zu | %zu\n", *(char*)vget(&chars, i), chars.length, chars.size, chars.datatype);
    vpop(&chars);

//    when code below is uncommented, the output will give segfault
//    vfreeElement(&strs);
    char *istr = *(char**)vget(&strs, i);
    printf("strs: %s > %p | %lu | %zu | %zu\n", istr, istr, strs.length, strs.size, strs.datatype);
    vpop(&strs);
  }

  vfree(&chars);
  vfree(&ints);
  vfree(&strs);
}
