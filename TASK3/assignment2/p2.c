#include <stdio.h>
#include <stdlib.h>
typedef struct{
char* name;
int age;}info;
int main()
{info object ={"me",35};
info* pointer=&object;
printf("\n name : %s",pointer->name);
printf("\n age : %d",pointer->age);
}
