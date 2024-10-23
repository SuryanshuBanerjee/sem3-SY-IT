#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Queue functions
void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1;
}

int isFull(Queue* q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) return;  // Ignore if full
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;  // No operation if empty
    int item = q->items[q->front];
    if (q->front >= q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return item;
}

// BFS function
void bfs(int graph[MAX_SIZE][MAX_SIZE], int startRow, int numRows) {
    Queue q;
    initQueue(&q);
    int visited[MAX_SIZE] = {0};

    visited[startRow] = 1;
    enqueue(&q, startRow);

    printf("BFS Sequence: ");
    while (!isEmpty(&q)) {
        int v = dequeue(&q);
        printf("%d ", v);

        for (int w = 0; w < numRows; w++) {
            if (graph[v][w] == 1 && !visited[w]) {
                enqueue(&q, w);
                visited[w] = 1;
            }
        }
    }
    printf("\n");
}

// Function to display the graph
void displayGraph(int graph[MAX_SIZE][MAX_SIZE], int numRows) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[MAX_SIZE][MAX_SIZE] = {0};
    int numRows;

    printf("Enter number of rows/columns (max %d): ", MAX_SIZE);
    scanf("%d", &numRows);

    if (numRows > MAX_SIZE) {
        printf("Number exceeds maximum limit.\n");
        return 1;
    }

    printf("Enter the adjacency matrix (%d x %d):\n", numRows, numRows);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\n");
    displayGraph(graph, numRows);

    int startRow;
    printf("Enter starting row for BFS: ");
    scanf("%d", &startRow);

    bfs(graph, startRow, numRows);

    return 0;
}
