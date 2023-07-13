#include <stdio.h>
#include <stdlib.h>
union database {
  struct {
    char name[50];
    char location[50];
  } shops;

  struct {
    int id;
    float price;
    int quantity;
  } product_info;

  struct {
    int id;
    int products_num;
  } category;
};
int main()
{
    union database object;
printf("%ld",sizeof(union database ));
printf("\n %ld",sizeof(object.shops ));
printf("\n %ld",sizeof(object.product_info ));
printf("\n %ld",sizeof(object.category ));
}
/*because the size of a structure is the sum of the size of all data members and the packing size and The size of the union is the size of its data member, which is the largest in size*/
