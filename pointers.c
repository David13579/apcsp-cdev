#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);

  float d = 1.5632;
  float e = 0.345;
  printf("The value of d is %f and the address is %p\n", d, (void*)&d);
  printf("The value of e is %f and the address is %p\n", e, (void*)&e);
  float* thingy = (void*)&d;
  float tmp = *thingy;
  *thingy=e;
  e=tmp;
  printf("The new value of d is %f and the address is %p\n", d, (void*)&d);
  printf("The new value of e is %f and the address is %p\n", e, (void*)&e);
}
