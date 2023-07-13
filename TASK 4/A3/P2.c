#include <stdio.h>
#include <stdlib.h>
#define ADD(num1, num2) (num1 + num2)
#define SUBTRACT(num1, num2) (num1 - num2)
int main()
{
    int x,y;
char operation;
printf("enter two numbers ");
   scanf("%d %d", &x, &y);
printf("enter operation ");
scanf(" %c",&operation);
  switch(operation) {
        case '+':
            printf("result of addition: %d\n", ADD(x, y));
            break;
        case '-':
            printf("result of subtraction: %d\n", SUBTRACT(x, y));
            break;
        default:
            printf("invalid operation.\n");
    }
    return 0;
}
