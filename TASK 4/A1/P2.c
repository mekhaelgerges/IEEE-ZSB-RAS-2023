#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
 {float real;
float imagine ;}number;
number add  (number x1,number x2);
int main ()
{number num1;
number num2;
number result ;
printf("enter the first real number :");
scanf("%f",&num1.real);
printf("enter the second real number :");
scanf("%f",&num2.real);
printf("enter the first imagine number :");
scanf("%f",&num1.imagine);
printf("enter the second imagine number :");
scanf("%f",&num2.imagine);
result=add ( num1, num2);
printf("%f+%fi", result.real, result.imagine);
};
number add (number x1, number x2)
{number x;
x.real=x1.real+x2.real;
x.imagine=x1.imagine+x2.imagine;
return x;};
