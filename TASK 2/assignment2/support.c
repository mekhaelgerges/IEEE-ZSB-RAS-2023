#include <stdio.h>

void test(void){
    int z=3;
    static int v=8;
    z++;
    printf("z is %d\n",z);
    num4++;
    printf("v is %d\n",v);
    return 0;
}

