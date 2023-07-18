#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main()
{
    int cols, rows,n;
    scanf("%d", &n);
    int start =0;
    int end=2*n-2;
    int size=2*n-1;
    int a[size][size];
    while(n!=0){


       for(rows=start; rows<=end; rows++)
       {

            for(cols=start; cols<=end; cols++)
            {
              if (rows==start||cols==start||cols==end||rows==end)
              {
              a[rows][cols]=n;
              }
            }



        }
        start++;
        end--;
        n--;
        }
        for(rows=0; rows<size; rows++)
       {

            for(cols=0; cols<size; cols++)
            {
              printf("%d ",a[rows][cols]);
            }
            printf("\n");
            }
return 0;}
