#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int roll_number;
    char name[50];
};

void insertStudent(struct Student students[], int *count);
void deleteLastStudent(struct Student students[], int *count);
void searchStudent(struct Student students[], int count);
void displayStudents(struct Student students[], int count);

int main() {
    struct Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n Roll Call List Menu \n");
        printf("1. Add a Student\n");
        printf("2. Remove the Last Student\n");
        printf("3. Find a Student\n");
        printf("4. Show All Students\n");
        printf("5. Exit (Oh no!)\n");
        printf("What will it be? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertStudent(students, &count);
                break;
            case 2:
                deleteLastStudent(students, &count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                displayStudents(students, count);
                break;
            case 5:
                printf("Goodbye! Don't forget to study! \n");
                break;
            default:
                printf("Oops! That’s against the rules. Try again!\n");
        }
    } while (choice != 5);

    return 0;
}

void insertStudent(struct Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Whoa there! The class is full! Can’t add more students!\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &students[*count].roll_number);
    printf("Enter name: ");
    scanf("%s", students[*count].name);

    (*count)++;
    printf(" Student added! Welcome, %s! Try to survive!\n", students[*count - 1].name);
}

void deleteLastStudent(struct Student students[], int *count) {
    if (*count <= 0) {
        printf("There's no one to remove, genius...\n");
        return;
    }

    printf("Farewell, %s! You were the last in line!\n", students[*count - 1].name);
    (*count)--;
}

void searchStudent(struct Student students[], int count) {
    if (count == 0) {
        printf("No students to find! The class is empty. \n");
        return;
    }

    int roll_number, found = 0;
    printf("Enter roll number to search: ");
    scanf("%d", &roll_number);

    for (int i = 0; i < count; i++) {
        if (students[i].roll_number == roll_number) {
            printf(" Student found! Time for punishment! Roll Number: %d, Name: %s\n", students[i].roll_number, students[i].name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No luck! No student with roll number %d found.\n", roll_number);
    }
}

void displayStudents(struct Student students[], int count) {
    if (count == 0) {
        printf("No students in the class... again...\n");
        return;
    }

    printf("\n Roll Call List \n");
    for (int i = 0; i < count; i++) {
        printf("Roll Number: %d, Name: %s\n", students[i].roll_number, students[i].name);
    }
}
