#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int priority[MAX];
    int size;
} PriorityQueue;

void createQueue(PriorityQueue* pq) {
    pq->size = 0;
}

int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

int isFull(PriorityQueue* pq) {
    return pq->size == MAX;
}

void insert(PriorityQueue* pq, int element, int priority) {
    if (isFull(pq)) {
        printf("Queue's packed! Can't squeeze in %d.\n", element);
        return;
    }

    int i = pq->size - 1;
    while (i >= 0 && priority > pq->priority[i]) {
        pq->data[i + 1] = pq->data[i];
        pq->priority[i + 1] = pq->priority[i];
        i--;
    }
    pq->data[i + 1] = element;
    pq->priority[i + 1] = priority;
    pq->size++;
    printf("Inserted %d with priority %d —welcome aboard!\n", element, priority);
}

int delete(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Nothing to delete...\n");
        return -1;
    }
    return pq->data[--pq->size];
}

void displayFront(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue's empty!\n");
    } else {
        printf("Front element: %d\n", pq->data[0]);
    }
}

void displayRear(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue's empty; no rear to show!\n");
    } else {
        printf("Rear element: %d\n", pq->data[pq->size - 1]);
    }
}

void displayAll(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue's empty...\n");
        return;
    }
    printf("Queue elements (priority):\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Element: %d, Priority: %d\n", pq->data[i], pq->priority[i]);
    }
}

int main() {
    PriorityQueue pq;
    createQueue(&pq);
    int choice, element, priority;

    do {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Create empty queue\n");
        printf("2. Insert an element\n");
        printf("3. Delete an element\n");
        printf("4. Display front element\n");
        printf("5. Display rear element\n");
        printf("6. Display all elements\n");
        printf("7. Exit\n");
        printf("Your move: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createQueue(&pq);
                printf("A new queue starts.\n");
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &element);
                printf("Enter priority: ");
                scanf("%d", &priority);
                insert(&pq, element, priority);
                break;
            case 3:
                element = delete(&pq);
                if (element != -1) {
                    printf("Farewell to %d—out it goes!\n", element);
                }
                break;
            case 4:
                displayFront(&pq);
                break;
            case 5:
                displayRear(&pq);
                break;
            case 6:
                displayAll(&pq);
                break;
            case 7:
                printf("Exiting - until next time!\n");
                break;
            default:
                printf("Don't try to be extra smart. Pick a valid option.\n");
        }
    } while (choice != 7);

    return 0;
}
