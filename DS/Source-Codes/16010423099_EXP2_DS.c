#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

void createSLL() {
    head = NULL;
}

int isEmpty() {
    return head == NULL;
}

void insertBegin(int newElement) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = newElement;
    newNode->next = head;
    head = newNode;
    printf("%d inserted at the beginning. A fine addition!\n", newElement);
}

void insertAfter(int newElement, int existingElement) {
    if (isEmpty()) {
        printf("The list is empty! Can't find that existing element.\n");
        return;
    }

    Node *current = head;
    while (current != NULL && current->data != existingElement) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Element %d not found. Can't add %d after it.\n", existingElement, newElement);
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = newElement;
    newNode->next = current->next;
    current->next = newNode;
    printf("%d inserted after %d.\n", newElement, existingElement);
}

int deleteBefore(int existingElement) {
    if (isEmpty() || head->data == existingElement) {
        printf("No nodes to delete before %d. Tragic!\n", existingElement);
        return -1;
    }

    Node *current = head;
    Node *prev = NULL;

    while (current->next != NULL && current->next->data != existingElement) {
        prev = current;
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Element %d not found. No deletion to be had!\n", existingElement);
        return -1;
    }

    int deletedData = prev->next->data;
    Node *temp = prev->next;
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d before %d.\n", deletedData, existingElement);
    return deletedData;
}

void display() {
    if (isEmpty()) {
        printf("The list is empty. Nothing to display.\n");
        return;
    }

    Node *current = head;
    printf("\nCurrent Elements in the List:\n");
    printf("-----------------------------\n");
    while (current != NULL) {
        printf("| %d ", current->data);
        current = current->next;
    }
    printf("|\n-----------------------------\n");
}

int main() {
    createSLL();
    int choice, newElement, existingElement;

    do {
        printf("\nSingly Linked List Menu\n");
        printf("1. Insert at the Beginning\n");
        printf("2. Insert After a Specified Node\n");
        printf("3. Delete Before a Specified Node\n");
        printf("4. Display All Elements\n");
        printf("5. Exit\n");
        printf("Choose your action: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the new element to insert: ");
                scanf("%d", &newElement);
                insertBegin(newElement);
                break;
            case 2:
                printf("Enter the new element to insert: ");
                scanf("%d", &newElement);
                printf("Enter the existing element after which to insert: ");
                scanf("%d", &existingElement);
                insertAfter(newElement, existingElement);
                break;
            case 3:
                printf("Enter the existing element before which to delete: ");
                scanf("%d", &existingElement);
                deleteBefore(existingElement);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Until next time!\n");
                break;
            default:
                printf("Unwise choice! Try again!\n");
        }
    } while (choice != 5);

    return 0;
}
