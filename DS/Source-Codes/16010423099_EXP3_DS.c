#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void createStack(Stack* s) {
    s->top = NULL;
}

void push(Stack* s, char x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = s->top;
    s->top = newNode;
}

char pop(Stack* s) {
    if (s->top == NULL) {
        printf("Stack Underflow\n");
        return '\0';
    }
    Node* temp = s->top;
    char popped = temp->data;
    s->top = s->top->next;
    free(temp);
    return popped;
}

int isEmpty(Stack* s) {
    return s->top == NULL;
}

char peek(Stack* s) {
    return (s->top != NULL) ? s->top->data : '\0';
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

void infixToPostfix(const char* infix, char* postfix) {
    Stack s;
    createStack(&s);
    int i, j = 0;
    char item;

    for (i = 0; infix[i] != '\0'; i++) {
        item = infix[i];
        if (isalnum(item)) {
            postfix[j++] = item;
        } else if (item == '(') {
            push(&s, item);
        } else if (item == '+' || item == '-' || item == '*' || item == '/' || item == '^') {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(item)) {
                postfix[j++] = pop(&s);
            }
            push(&s, item);
        } else if (item == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        } else {
            printf("Oops! Invalid character in infix expression\n");
            return;
        }
    }

    while (!isEmpty(&s)) {
        char top = pop(&s);
        if (top == '(') {
            printf("Oops! Mismatched parentheses\n");
            return;
        }
        postfix[j++] = top;
    }

    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
