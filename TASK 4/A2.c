#include <stdio.h>
#include <stdlib.h>
#include <string.h>
enum operations {pluse=43,munse=45, multiple=42, division=47};
enum operations1 {plusee,munsee, multiplee, divisione,a,b,c,d};
int main ()
{
char x;
printf("enter the operation (+,-,*,/):");
scanf("%c",&x);
int num1;
int num2;
float result;
printf("enter the first number ");
scanf("%d",&num1);
printf("enter the second number ");
scanf("%d",&num2);
int y=x;
enum operations operation=y;
if (operation ==43){
result=num1+num2;
printf("%f", result);}
if (operation ==45){
result=num1-num2;
printf("%f", result);}
if (operation ==42){
result=num1*num2;
printf("%f", result);}
if (operation ==47){
result=num1/num2;
printf("%f", result);}
printf("\n the size of the enum %d",sizeof(enum operations ));
//the size of the enum=4

printf("\n the size of the enum after adding other elments= %d",sizeof(enum operations1 ));
}
