#include <stdio.h>
#include <stdlib.h>
struct database {
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
    struct database object;
printf("%ld",sizeof(struct database ));
printf("\n %ld",sizeof(object.shops ));
printf("\n %ld",sizeof(object.product_info ));
printf("\n %ld",sizeof(object.category ));
}
