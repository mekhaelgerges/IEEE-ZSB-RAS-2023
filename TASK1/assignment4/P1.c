#include <stdio.h>
#include <stdlib.h>
int main()
{
char x[200];
int i;

scanf("%[^\n]%*c",&x);
printf("%s",x);
}


