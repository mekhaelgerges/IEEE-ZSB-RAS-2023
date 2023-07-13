#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void printList(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert(Node **head, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void delete(Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

int main() {
    Node *head = NULL;
    char c;
    int data;

    while (1) {
        scanf(" %c", &c);
        if (c == '+') {
            scanf("%d", &data);
            insert(&head, data);
        } else if (c == '-') {
            delete(&head);
        } else if (c == 'p') {
            printList(head);
        } else if (c == 'x') {
            break;
        }
    }

    return 0;
}