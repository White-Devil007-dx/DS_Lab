#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

/* --- Separate Chaining Structures and Functions --- */

struct Node {
    int data;
    struct Node* next;
};

struct Node* chain[TABLE_SIZE];

void initChain() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        chain[i] = NULL;
    }
}

void insertChain(int key) {
    int index = key % TABLE_SIZE;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = key;
    newNode->next = NULL;

    if (chain[index] == NULL) {
        chain[index] = newNode;
    } 
    else {
        struct Node* temp = chain[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at chain index %d\n", key, index);
}

void displayChain() {
    printf("\n--- Separate Chaining Hash Table ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* temp = chain[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

/* --- Linear Probing Functions --- */
int linearHash[TABLE_SIZE];

void initLinear() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        linearHash[i] = -1; // -1 indicates empty slot
    }
}

void insertLinear(int key) {
    int index = key % TABLE_SIZE;
    int i = 0;
    while (i < TABLE_SIZE) {
        int probeIndex = (index + i) % TABLE_SIZE;
        if (linearHash[probeIndex] == -1) {
            linearHash[probeIndex] = key;
            printf("Inserted %d at index %d\n", key, probeIndex);
            return;
        }
        i++;
    }
    printf("Hash table is full! Cannot insert %d\n", key);
}

void displayLinear() {
    printf("\n--- Linear Probing Hash Table ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (linearHash[i] == -1)
            printf("Index %d: EMPTY\n", i);
        else
            printf("Index %d: %d\n", i, linearHash[i]);
    }
}

/* --- Quadratic Probing Functions --- */
int quadHash[TABLE_SIZE];

void initQuad() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        quadHash[i] = -1;
    }
}

void insertQuad(int key) {
    int index = key % TABLE_SIZE;
    int i = 0;
    while (i < TABLE_SIZE) {
        int probeIndex = (index + i * i) % TABLE_SIZE;
        if (quadHash[probeIndex] == -1) {
            quadHash[probeIndex] = key;
            printf("Inserted %d at index %d\n", key, probeIndex);
            return;
        }
        i++;
    }
    printf("Cannot insert %d using quadratic probing (table full or quadratic cycle)\n", key);
}

void displayQuad() {
    printf("\n--- Quadratic Probing Hash Table ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (quadHash[i] == -1)
            printf("Index %d: EMPTY\n", i);
        else
            printf("Index %d: %d\n", i, quadHash[i]);
    }
}

/* --- Main Menu --- */
int main() {
    int choice, subChoice, key;
    initChain();
    initLinear();
    initQuad();

    do {
        printf("\n=== HASH COLLISION RESOLUTION MENU ===");
        printf("\n1. Linear Probing");
        printf("\n2. Quadratic Probing");
        printf("\n3. Separate Chaining");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                do {
                    printf("\n--- Linear Probing Menu ---");
                    printf("\n1. Insert");
                    printf("\n2. Display");
                    printf("\n3. Back to Main Menu");
                    printf("\nEnter choice: ");
                    scanf("%d", &subChoice);
                    if (subChoice == 1) {
                        printf("Enter key to insert: ");
                        scanf("%d", &key);
                        insertLinear(key);
                    } else if (subChoice == 2) {
                        displayLinear();
                    }
                } while (subChoice != 3);
                break;

            case 2:
                do {
                    printf("\n--- Quadratic Probing Menu ---");
                    printf("\n1. Insert");
                    printf("\n2. Display");
                    printf("\n3. Back to Main Menu");
                    printf("\nEnter choice: ");
                    scanf("%d", &subChoice);
                    if (subChoice == 1) {
                        printf("Enter key to insert: ");
                        scanf("%d", &key);
                        insertQuad(key);
                    } else if (subChoice == 2) {
                        displayQuad();
                    }
                } while (subChoice != 3);
                break;

            case 3:
                do {
                    printf("\n--- Separate Chaining Menu ---");
                    printf("\n1. Insert");
                    printf("\n2. Display");
                    printf("\n3. Back to Main Menu");
                    printf("\nEnter choice: ");
                    scanf("%d", &subChoice);
                    if (subChoice == 1) {
                        printf("Enter key to insert: ");
                        scanf("%d", &key);
                        insertChain(key);
                    } else if (subChoice == 2) {
                        displayChain();
                    }
                } while (subChoice != 3);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}