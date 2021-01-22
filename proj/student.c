//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

int numStudents = 0;

Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  Student* st= (Student*)malloc(50*sizeof(Student));
  st->firstName=(char*)malloc(50*sizeof(fname));
  st->lastName=(char*)malloc(50*sizeof(lname));
  st->age=age;
  st->id=id;
  strcpy(st->firstName,fname);
  strcpy(st->lastName,lname);
  students[numStudents]=st;
  numStudents++;
}


void deleteStudent(Student* student)
{
  free(student->firstName);
  free(student->lastName);
  free(student);
}


void deleteStudents()
{
  for(int i=0;i<numStudents;i++)
  {
  deleteStudent(students[i]);
  students[i]=0;
  }
  numStudents=0;
}


void saveStudents(int key)
{
  FILE* studentdata;
  studentdata = fopen("studentdata.txt","w");
  char tmpAge[256];
  char tmpid[256];
  if (studentdata)
  {
    for (int i=0;i<numStudents;i++){
      Student* st=students[i];
      sprintf(tmpAge,"%d",st->age);
      sprintf(tmpid,"%ld",st->id);
      caesarEncrypt(st->firstName,key);
      caesarEncrypt(st->lastName,key);
      caesarEncrypt(tmpAge,key);
      caesarEncrypt(tmpid,key);
      printf("saving: %s %s %s %s\n",st->firstName,st->lastName,tmpAge,tmpid);
      fprintf(studentdata,"Student %d: %s %s %s %s\n",i,st->firstName,st->lastName,tmpAge,tmpid);
    }
    printf("saved %d students\n",numStudents);
    fclose(studentdata);
  }
}


void loadStudents(int key)
{
  if(numStudents>0)
    deleteStudents();
  FILE* studentread;
  studentread = fopen("studentdata.txt","r");
  if (studentread){
    while (1) {
      char b1[256];
      char b2[256];
      char b3[256];
      char b4[256];
      int age; long id;
      if(fscanf(studentread,"%s %s %s %s",b1,b2,b3,b4)==4){
        caesarDecrypt(b1,key);
        caesarDecrypt(b2,key);
        caesarDecrypt(b3,key);
        caesarDecrypt(b4,key);
        sscanf(b3, "%d",&age);
        sscanf(b4, "%ld",&id);
        createStudent(b1,b2,age,id);
        }
      else{
        break;
        }
      }
    }
  printf("%d Students loaded", numStudents);
  fclose(studentread);
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




