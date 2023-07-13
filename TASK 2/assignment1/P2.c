
#include <stdio.h>

int main() {
    int a=0xfffff1;
    int *ptr=&a;
    printf("%x",*ptr);
    *ptr++;
    printf(" \n %x",*ptr);
    *++ptr;
    printf("\n %x",*ptr);
    ++*ptr;
    printf("\n %x",*ptr);}

