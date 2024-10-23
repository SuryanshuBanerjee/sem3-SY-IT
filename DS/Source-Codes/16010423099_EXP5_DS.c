#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* ROOT = NULL;

void createBST() {
    ROOT = NULL;
}

Node* createNode(int element) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = element;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(int element) {
    Node* newNode = createNode(element);
    if (ROOT == NULL) {
        ROOT = newNode;
        return;
    }
    Node* current = ROOT, *parent = NULL;
    while (current != NULL) {
        parent = current;
        if (element < current->data) current = current->left;
        else if (element > current->data) current = current->right;
        else {
            free(newNode);
            return;
        }
    }
    if (element < parent->data) parent->left = newNode;
    else parent->right = newNode;
}

Node* search(int element) {
    Node* current = ROOT;
    while (current != NULL) {
        if (element == current->data) return current;
        else if (element < current->data) current = current->left;
        else current = current->right;
    }
    return NULL;
}

Node* findMin(Node* node) {
    while (node && node->left != NULL) node = node->left;
    return node;
}

Node* delete(int element) {
    Node* current = ROOT, *parent = NULL;
    while (current != NULL && current->data != element) {
        parent = current;
        current = (element < current->data) ? current->left : current->right;
    }
    if (current == NULL) return NULL;

    if (current->left == NULL && current->right == NULL) {
        if (current == ROOT) ROOT = NULL;
        else if (current == parent->left) parent->left = NULL;
        else parent->right = NULL;
        free(current);
    } else if (current->left == NULL || current->right == NULL) {
        Node* child = (current->left != NULL) ? current->left : current->right;
        if (current == ROOT) ROOT = child;
        else if (current == parent->left) parent->left = child;
        else parent->right = child;
        free(current);
    } else {
        Node* successor = findMin(current->right);
        current->data = successor->data;
        delete(successor->data);
    }
    return current;
}

void displayInorder(Node* node) {
    if (node != NULL) {
        displayInorder(node->left);
        printf("%d ", node->data);
        displayInorder(node->right);
    }
}

int main() {
    createBST();
    int choice, element;

    do {
        printf("\n--- BST Menu ---\n");
        printf("1. Insert an element\n");
        printf("2. Search for an element\n");
        printf("3. Delete an element\n");
        printf("4. Display all elements (Inorder)\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                insert(element);
                break;
            case 2:
                printf("Enter element to search: ");
                scanf("%d", &element);
                Node* found = search(element);
                printf(found ? "Element %d found.\n" : "Element %d not found.\n", element);
                break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &element);
                if (delete(element)) {
                    printf("Element %d has left the building.\n", element);
                } else {
                    printf("Element %d couldn't be found for deletion.\n", element);
                }
                break;
            case 4:
                printf("Elements in BST (Inorder): ");
                displayInorder(ROOT);
                printf("\n");
                break;
            case 5:
                printf("Exiting—until we meet again!\n");
                break;
            default:
                printf("Oops! That’s not on the menu. Try again!\n");
        }
    } while (choice != 5);

    return 0;
}
