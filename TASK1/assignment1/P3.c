#include <stdio.h>

void count_frequency(int arr[], int size)
{
    int f[size];
    int i, j;

    for(i = 0; i < size; i++) {
        f[i] = -1;
    }

    for(i = 0; i < size; i++) {
        int count = 1;
        for(j = i + 1; j < size; j++) {
            if(arr[i] == arr[j]) {
                count++;
                f[j] = 0;
            }
        }

        if(f[i] != 0) {
            f[i] = count;
        }
    }

    printf("Element  Frequency\n");
    for(i = 0; i < size; i++) {
        if(f[i] != 0) {
            printf("%d \t\t %d\n", arr[i], f[i]);
        }
    }
}

int main()
{
    int a[]={1,2,3,5,8,9,1,3,4,5,32,1,5,3};

    int s = sizeof(a) / sizeof(a[0]);

    count_frequency(a, s);

    return 0;
}
