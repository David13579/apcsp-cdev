#include <stdio.h>
#include <math.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%d", b);
  }
}



// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main
float areaOfCircle(float radius)
{
  float pi=3.14159265;
  return pi*radius*radius;
}



int main(int argc, char* argv[]) 
{
  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2
  float start = 5.2;
  int reps = 3;
  printf("Input the start of the circle:");
  scanf("%f",&start);
  printf("Input the reps(start+reps-1 is the end of the circle):");
  scanf("%d",&reps);
  // for testing only - do not change
  getTestInput(argc, argv, &start, &reps);

  printf("Calculating area of circle starting at %f, and ending at %f\n", start, start+reps-1);
  
  // add your code below to call areaOfCircle function with values between
  // start and end
  float rad=(reps-1)/2;
  for( int i=0;i<reps;i++)
  {
  printf("Area of the circle is %f\n",areaOfCircle(start));
  start++;
  }
}
