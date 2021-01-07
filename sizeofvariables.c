#include<stdio.h>

int main()
{
  int a = 545;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));

  char b = "hello";

  // print value and size of a char variable
  printf("char b value: %d and size: %lu bytes\n", b, sizeof(b));

  float c = 0.005;

  // print value and size of a float variable
  printf("float c value: %d and size: %lu bytes\n", c, sizeof(c));

  double d = 0.015234;

  // print value and size of a float variable
  printf("double d value: %d and size: %lu bytes\n", d, sizeof(d));


}

