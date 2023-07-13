#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char str[1000000];
    int i,j,q=0;
    scanf("%s",&str);

    for(j=0;j<strlen(str);j++)
        {

            if(str[j] == '0'){q++;}
        }
        printf("%d ",q);
        q=0;

        for(j=0;j<strlen(str);j++)
        {

            if(str[j] == '1'){q++;}
        }
        printf("%d ",q);
        q=0;
        for(j=0;j<strlen(str);j++)
        {

            if(str[j] == '2'){q++;}
        }
        printf("%d ",q);
        q=0;
        for(j=0;j<strlen(str);j++)
        {

            if(str[j] == '3'){q++;}
        }
        printf("%d ",q);
        q=0;
        for(j=0;j<strlen(str);j++)
        {

            if(str[j] == '4'){q++;}
        }
        printf("%d ",q);
        q=0;
        for(j=0;j<strlen(str);j++)
        {

            if(str[j] == '5'){q++;}
        }
        printf("%d ",q);
        q=0;
        for(j=0;j<strlen(str);j++)
        {

            if(str[j] == '6'){q++;}
        }
        printf("%d ",q);
        q=0;
        for(j=0;j<strlen(str);j++)
        {

            if(str[j] == '7'){q++;}
        }
        printf("%d ",q);
        q=0;
        for(j=0;j<strlen(str);j++)
        {

            if(str[j] == '8'){q++;}
        }
        printf("%d ",q);
        q=0;
        for(j=0;j<strlen(str);j++)
        {

            if(str[j] == '9'){q++;}
        }
        printf("%d",q);
        q=0;
    }
