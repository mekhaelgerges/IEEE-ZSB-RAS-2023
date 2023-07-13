#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 struct test{
    int id;
char name[10];
char class_id
};
struct test2{
    char name[10];
    int id;
    char class_id
};

int main()
{
struct test x={1,"me","me"};
struct test2 y={"me",1,"me"};
printf("%ld",sizeof(struct test));
printf("\n %ld",sizeof(struct test2));
}
/* the size changes because the compiler is not allowed to reorder fields ,so the size of the struct may change as the result of adding some padding*\
