
#include <stdio.h>
#include <string.h>

int main() {
    int max_length;
    printf("Enter the maximum length for the name: ");
    scanf("%d", &max_length);

    char name[max_length + 1];
    printf("Enter the name: ");
    scanf("%s", name);

    printf("Name: %s\n", name);

    int freq[256] = {0};
    int max_freq = 0;
    char max_char;
    for (int i = 0; i < strlen(name); i++) {
        freq[(int)name[i]]++;
        if (freq[(int)name[i]] > max_freq) {
            max_freq = freq[(int)name[i]];
            max_char = name[i];
        }
    }

    printf("Most repeated character: %c\n", max_char);
    printf("Frequency: %d\n", max_freq);

    return 0;
}