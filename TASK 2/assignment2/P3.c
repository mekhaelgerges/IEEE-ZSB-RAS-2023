#include <stdio.h>

#include"list/list.h"
void ext_fun(void);
void test(void);
int x=5;
int main(){
    auto int y=1;
    register int z=2;
    printf("num is %d\n",z);
    printf("num is %d\n",y);
     x++;
     printf("x= %d\n",x);
     test();
     test();
     ext_fun();

    return 0;
}
