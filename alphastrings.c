#include <stdio.h>
#include <string.h>
int compare();
int main()
{
char firststring;
char secondstring[]="abcdefghijklmnopqrstuvwxyz";
  for (int i=0;i<26;i++)
  {
  firststring='a'+i;
  printf("%c",firststring);
  }
printf("\n");
  for(int i=0;i<26;i++)
  {
  printf("%c",secondstring[i]);
  }
printf("\n");
int compare;
char tmpstring[2];
tmpstring[0]=firststring;
tmpstring[1]='\0';
compare= strcmp(tmpstring, secondstring);
  if (compare==0)
  {
  printf("Equal\n");
  }
  else
  {
  printf("Not Equal\n");
  }
  for (int i=0;i<26;i++)
  {
  secondstring[i]=secondstring[i]-32;
  }
  for (int i=0;i<26;i++)
  {
  firststring='a'+i;
  printf("%c",firststring);
  }
  printf("\n");
  for (int i=0;i<26;i++)
  {
  printf("%c",secondstring[i]);
  }
  printf("\n");
compare= strcmp(tmpstring, secondstring);
  if (compare==0)
  {
  printf("Equal\n");
  }
  else
  {
  printf("Not Equal\n");
  }
char tmp[26];
for (int i=0;i<26;i++)
  {
  firststring='a'+i;
  tmp[i]=firststring;
  }
char thirdstring[52];
strcpy(thirdstring,tmp);
strncat(thirdstring,secondstring,52);
printf("%s\n",thirdstring);
}

