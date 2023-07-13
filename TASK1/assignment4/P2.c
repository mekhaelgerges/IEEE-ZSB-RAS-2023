#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
char x[10];
int i;
scanf("%[^\n]%*c",&x);
for (i=0;i<10;i++){
    printf("%c \n",x[i]);
}
}
