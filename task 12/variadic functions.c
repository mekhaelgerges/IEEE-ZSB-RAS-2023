#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ELEMENT 1
#define MAX_ELEMENT 1000000
int  sum (int count,...) {
    va_list args;
    va_start(args, count);
    int s=0;
    int i;
    for (i=0;i<count;i++)
    {
        int x=va_arg(args, int);
        s=x+s;
    }
    va_end(args);
    return s;


}

int min(int count,...) {
    int min=MAX_ELEMENT;
     va_list args;
    va_start(args, count);

    int i;
    for (i=0;i<count;i++)
    {
        int x=va_arg(args, int);
        if(x<min)
        {
            min=x;
        }

    }
    va_end(args);
return min;
}

int max(int count,...) {
    int max=0;
    va_list args;

    va_start(args, count);

    int i;
    for (i=0;i<count;i++)
    {
        int x=va_arg(args, int);
        if(x>max)
        {
            max=x;
        }

    }
    va_end(args);
return max;
}



int test_implementations_by_sending_three_elements() {
