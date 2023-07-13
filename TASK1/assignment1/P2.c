#include <stdio.h>

int main() {
    int arr[100], f[100], n, i, j;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        f[i] = -1;
    }


    for (i = 0; i < n; i++) {
        int count = 1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                f[j] = 0;
            }
        }
        if (f[i] != 0) {
            f[i] = count;
        }
    }


    printf("The unique elements in the array are: ");
    for (i = 0; i < n; i++) {
        if (f[i] == 1) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}
