#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{char name[50];
char adrees[20];
int roll_number;
int age ;
int marks;}student;
int main()
{student student[15];
int i;
int z=0;
for(i=0;i<15;i++){
printf("enter the student name");
scanf("%s",&student[i].name);
printf("enter the student adress");
scanf("%s",&student[i].adrees);
printf("enter the student age");
scanf(" %d",&student[i].age);
printf("enter the student mark \n");
scanf(" %d",&student[i].marks);
printf("enter the student roll number");
scanf(" %d",&student[i].roll_number);
printf("\n");}
for(i=0;i<15;i++){
printf("\n [");
printf("\n student name: %s",student[i].name);
printf("\n student address: %s",student[i].adrees);
printf("\n student age: %d",student[i].age);
printf("\n student mark: %d",student[i].marks);
printf("\n student roll number: %d",student[i].roll_number);
printf("]");

}
for(i=1;i<15;i++){
if (student[i].marks <12){
z++;}
}
printf("the number of marks less than 12 is  %d \n",z);
}
