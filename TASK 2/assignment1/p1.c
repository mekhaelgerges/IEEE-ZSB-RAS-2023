#include<stdio.h>

int main()
{
    int* p1;
    char* p2;
    long long* p3;
    printf("int%p  char%p  long long%p  ", p1,p2,p3);
    p1++;
    p2++;
    p3++;
    printf(" \n int%p  char%p  long long%p", p1,p2,p3);
    return 0;}
