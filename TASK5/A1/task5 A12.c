#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{int n =3;
int* ptr=(int*)malloc(n* sizeof (int));
int* ptr1=(int*)calloc(n,sizeof (int));
  printf(" malloc memory");
for (int i=0;i<3;i++)
{
printf("\n %p",(ptr+i));
}
printf(" \n calloc memory");
for (int i=0;i<3;i++)
{
printf("\n %p",(ptr1+i));
}
free(ptr);
ptr =ptr=(int*)malloc(10* sizeof (int));
printf(" \n new  malloc memory");
for (int i=0;i<10;i++)
{
printf("\n %p",(ptr+i));
}}
/* 
if i hadn't free the space 
space leak would have happened */