#include <stdio.h>
#include <string.h>


// student structure
//struct Student...
struct Student {
  char firstname[256];
  char lastname[256];
  int age;
  int id;

};

void printStudent(struct Student* student)
{
  printf("  Student:%s %s\n",student->firstname,student->lastname);
  printf("    age:%d\n",student->age);
  printf("    id:%d\n\n",student->id);
}


void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
  for(int i=0;i<num;i++)
  {
  printf("----- student ------\n");
  printStudent(&students[i]);
  }
}


int main()
{

  // an array of students
  //xxx students;
  struct Student students[10];
  int numStudents = 0;
  while (1)
  {
    char c;
    char input[100];
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q')
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students,numStudents);
      continue;
    }
    else if (c == 'a')
    {
      char input[256];
      char first[256];
      char last[256];
      int age;
      int id;
      // enter a new student
      printf("First Name:");
      fgets(input, 256, stdin);
      sscanf(input, "%s", first);

      printf("Last Name:");
      fgets(input, 256, stdin);
      sscanf(input, "%s", last);

      printf("Age:");
      while(1)
      {
      fgets(input, 256, stdin);
      if (sscanf(input, "%d",&age) ==1) break;
      printf("Invalid, try again!\n");
      }

      printf("Id:");
      while (1)
      {
      fgets(input,256,stdin);
      if (sscanf(input, "%d",&id) ==1) break;
      printf("Invalid, try again!\n");
      }
      strcpy(students[numStudents].firstname, first);
      strcpy(students[numStudents].lastname, last);
      students[numStudents].age=age;
      students[numStudents].id=id;
      numStudents++;
    }
   else{
   printf("Please input a valid input");
   }
  }
  
  printf("\nGoodbye!\n");
}
