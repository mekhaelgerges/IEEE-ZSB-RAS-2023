#include <stdio.h>

void add(int *v, int *j, int *result) {
    *result = *v + *j;
}

int main() {
    int x, y, sum;
    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    add(&x, &y, &sum);

    printf("The sum of %d and %d is %d.\n", x,y, sum);

    return 0;
}

