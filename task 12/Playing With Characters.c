#include <stdio.h>
int main() {
char ch;
char *str;
char str1[100];

scanf("%c \n %s \n  %[^\n]s \n ",&ch,&str,&str1);

printf("%c \n",ch);
printf("%s \n",&str);
printf("%s \n",&str1);

return 0;

}
