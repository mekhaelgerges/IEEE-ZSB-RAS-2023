#include <stdio.h>
#include <stdlib.h>
 
int main()
{
  int* time=calloc(3, sizeof(int));
for (int i=0;i<3;i++)
{scanf("%d:",(time+i));}
for (int i=0;i<3;i++)
{printf("%d:",*(time+i));}}