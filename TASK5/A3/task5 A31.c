#include <stdio.h>
#define MAX 1
#include<stdio.h>
inline int mul(int a, int b) {
   return (a*b);}
int main() {
printf("%d \n",sizeof(MAX));
printf("%d",sizeof(mul));}
/* inline functions are parsed by the compiler, whereas macros in a program are expanded by the preprocessor*/
/*we can use macros whenever we want to repeatedly use a single value or a piece of code in our programs*/
/*An inline function is one for which the compiler copies the code from the function definition directly into the code of the calling function rather than creating a separate set of instructions in memory*/