#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main ()
{int n =3;
int *ptr=(int*)malloc(n* sizeof (int));
int *ptr1=(int*)calloc(n,sizeof (int));
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

ptr=realloc(ptr,3 *sizeof(int));
ptr1=realloc(ptr1,3 *sizeof(int));
printf("\n new malloc memory");
 for (int i=0;i<3;i++)
{
printf("\n %p",(ptr+i));
}
printf("\n new calloc memory");
 for (int i=0;i<3;i++)
{
printf("\n %p",(ptr1+i));

}}
 /*
new malloc memory
 0x740002c010
 0x740002c014
 0x740002c018
 new calloc memory
 0x740002c020
 0x740002c024
 0x740002c028
 */
