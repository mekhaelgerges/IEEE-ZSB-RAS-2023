#include <stdio.h>
#include <stdlib.h>
int main()
{
   int x=10;
   int y=20;
   int z=30;
   int *p=&x;
   int *q=&y;
   int *r=&z;
   printf("x=%d \n y=%d \n z=%d \n p=%d \n q=%d \n r=%d \n *p=%d\n*q=%d\n*r=%d\n",x,y,z,p,q,r,*p,*q,*r);
   printf("swaping pointers.... ");
   int *temp=r;
   r=p;
   p=q;
   q=temp;
   printf("\nx=%d \n y=%d \n z=%d \n p=%d \n q=%d \n r=%d \n *p=%d\n*q=%d\n*r=%d\n",x,y,z,p,q,r,*p,*q,*r);
}
