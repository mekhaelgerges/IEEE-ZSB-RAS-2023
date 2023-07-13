#include <stdio.h>

int main() {
    char x[100], y[100];
    int i, z = 1;

    printf("Enter first string: ");
    scanf("%s", x);

    printf("Enter second string: ");
    scanf("%s", y);

    for (i = 0; x[i] != '\0' || y[i] != '\0'; i++) {
        if (x[i] != y[i]) {
            z = 0;
            break;
        }
    }

    if (z) {
        printf("Strings are equal\n");
    } else {
        printf("Strings are not equal\n");
    }

    return 0;
}
