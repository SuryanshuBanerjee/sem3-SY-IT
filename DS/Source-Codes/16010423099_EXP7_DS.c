#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define MAX_LENGTH 20

typedef struct {
    char key[MAX_LENGTH];
    char value[MAX_LENGTH];
    int isOccupied;
} Entry;

Entry hashTable[TABLE_SIZE];

int hash(const char* key) {
    int hashValue = 0;
    while (*key) {
        hashValue += *key++;
    }
    return hashValue % TABLE_SIZE;
}

void insert() {
    char key[MAX_LENGTH], value[MAX_LENGTH];
    printf("Let's add a new entry.\n");
    printf("Enter the key: ");
    scanf("%s", key);
    printf("Enter the value: ");
    scanf("%s", value);

    int index = hash(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = (index + i) % TABLE_SIZE;
        if (!hashTable[pos].isOccupied) {
            strcpy(hashTable[pos].key, key);
            strcpy(hashTable[pos].value, value);
            hashTable[pos].isOccupied = 1;
            printf("Success! Stored '%s' at position %d.\n", key, pos);
            return;
        }
    }
    printf("The table is full! Cannot add more entries.\n");
}

void search() {
    char key[MAX_LENGTH];
    printf("Searching for a key? Enter it here: ");
    scanf("%s", key);

    int index = hash(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = (index + i) % TABLE_SIZE;
        if (hashTable[pos].isOccupied && strcmp(hashTable[pos].key, key) == 0) {
            printf("Found it! Key: '%s', Value: '%s' at position %d.\n", hashTable[pos].key, hashTable[pos].value, pos);
            return;
        }
    }
    printf("No match found for that key.\n");
}

void delete() {
    char key[MAX_LENGTH];
    printf("Enter the key to delete: ");
    scanf("%s", key);

    int index = hash(key);
    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = (index + i) % TABLE_SIZE;
        if (hashTable[pos].isOccupied && strcmp(hashTable[pos].key, key) == 0) {
            hashTable[pos].isOccupied = 0;
            printf("The key '%s' at position %d has been deleted.\n", key, pos);
            return;
        }
    }
    printf("That key isn't in the table.\n");
}

void display() {
    printf("\nContents of the hash table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].isOccupied) {
            printf("Position %d: Key = '%s', Value = '%s'\n", i, hashTable[i].key, hashTable[i].value);
        } else {
            printf("Position %d: (Empty)\n", i);
        }
    }
}

int main() {
    int choice;
    printf("Welcome to the Dictionary Program!\n");
    while (1) {
        printf("\nChoose an option:\n1. Insert Entry\n2. Search for Key\n3. Delete Entry\n4. Display Table\n5. Exit\nYour choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert(); break;
            case 2: search(); break;
            case 3: delete(); break;
            case 4: display(); break;
            case 5: printf("Exiting program. Goodbye!\n"); exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }
}
