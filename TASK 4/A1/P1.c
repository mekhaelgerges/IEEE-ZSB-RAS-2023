#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{char name[50] ;// 50 characters with 8 bits each
char adrees[20] ;// 20 characters with 8 bits each
int roll_number :4;
int age :8 ;
int marks: 3;}student;
void print_student(student x);
int main()
{student student[15];
int i;
for(i=0;i<15;i++){

student[i].age=20+i;
strcpy(student[i].name,"kevin");
strcpy(student[i].adrees,"kevin");
student[i].marks=i;
student[i].roll_number=120+i;
print_student(student[i]);
};
}

void print_student(student x){
printf("\n [");
printf(" %s",x.name);
printf(" %s",x.adrees);
printf(" %d",x.age);
printf(" %d",x.marks);
printf(" %d",x.roll_number);
printf("]");}
 //the processor will deal with each member of the stract with the given bit field as it will occupie only the bits that its allowed too
