#include<stdio.h>
int y(int x){
x++;
printf("%d",x);
}

int main()
{
 void (*p)(int);
  p=&y;
(*p)(7);}

