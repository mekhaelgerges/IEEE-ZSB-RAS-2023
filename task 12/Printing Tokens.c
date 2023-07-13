#include <stdio.h>
int main() {

char str[10000];
char str1[10000];
int i,j;
scanf("%[^\n]s",&str);
for(i=0;i<strlen(str)+1;i++){
str1[i]=str[i];
if (str[i]==' ')
{str1[i]='\n';}
}

printf("%s \n",str1);}

