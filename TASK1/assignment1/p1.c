#include <stdio.h>
#include <stdlib.h>
int main(main)
{
     int l=0;
     printf("enter the size of the arry :");
    scanf("%d",&l);
    int i=0;
    int v=0;
    int x=0;
    int z=0;
    char c[l];
    for(i=0;i<l;i++){
    v=0;
    scanf("%s",&c[i]);

    }
    for(v=0;v<l;v++){

        for (x=0;x<l;x++)
        {
            if ((c[x]==c[v])&&(v!=x)){
                    z++;
            }
        else {
            printf("");
        }
        }
        x=0;
    }
    printf("the number of duplicate = %d",z/(l-1));
    return 0;
}
