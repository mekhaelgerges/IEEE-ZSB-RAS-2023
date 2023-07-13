
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
int day ;
int month;
int year;} date;
int main (){
int i ;
int f=0;

date today;
printf("enter a the date as numbers \n day:");
scanf("%d",&today.day);
printf("\n month:");
scanf("%d",&today.month);
printf("\n year:");
scanf("%d",&today.year);
date today2;
printf("enter another date as numbers \n day:");
scanf("%d",&today2.day);
printf("\n month:");
scanf("%d",&today2.month);
printf("\n year:");
scanf("%d",&today2.year);;


if ((today.day==today2.day)&&(today.month==today2.month)&&(today.year==today2.year)){
printf("the dates are  equal");
}else{
printf("the dates are not equal");
}}




