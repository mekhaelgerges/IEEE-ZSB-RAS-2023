
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STOP_CODE "!!"

int main() {
    char input[100];
    while (true) {
        printf("Enter a string: ");
        scanf("%s", input);

        if (strcmp(input, STOP_CODE) == 0) {
            break;
        }

        int freq[256] = {0};
        for (int i = 0; i < strlen(input); i++) {
            freq[(int)input[i]]++;
        }

        printf("Unique characters: ");
        for (int i = 0; i < 256; i++) {
            if (freq[i] == 1) {
                printf("%c ", (char)i);
            }
        }
        printf("\n");
    }

    return 0;
}
