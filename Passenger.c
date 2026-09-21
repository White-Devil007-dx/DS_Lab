#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct passenger {
    int id;
    char passengerName[100];
    struct passenger *prev;
    struct passenger *next;
};

struct passenger *first = NULL;
struct passenger *last = NULL;
struct passenger *newNode;
struct passenger *current;
int position;

void addPassenger()
{
    int id;
    char name[100];

    printf("Enter passenger ID: ");
    scanf("%d", &id);

    printf("Enter passenger name: ");
    scanf("%99s", name);

    newNode = (struct passenger *)malloc(sizeof(struct passenger));
    newNode->id = id;
    strcpy(newNode->passengerName, name);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (first == NULL) {
        first = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }

    printf("Passenger Check-In Successful\n");
}

void addPriorityPassenger()
{
    int id;
    char name[100];

    printf("Enter passenger ID: ");
    scanf("%d", &id);

    printf("Enter passenger name: ");
    scanf("%99s", name);

    newNode = (struct passenger *)malloc(sizeof(struct passenger));
    newNode->id = id;
    strcpy(newNode->passengerName, name);
    newNode->prev = NULL;
    newNode->next = NULL;

    if (first == NULL) {
        first = newNode;
        last = newNode;
    } else {
        newNode->next = first;
        first->prev = newNode;
        first = newNode;
    }

    printf("Priority Check-In Successful\n");
}

void findPassenger()
{
    int id;
    printf("Enter passenger ID: ");
    scanf("%d", &id);

    current = first;

    if (first == NULL) {
        printf("Passenger list is empty\n");
    } else {
        for (position = 1; current != NULL; position++) {
            if (current->id == id) {
                printf("Passenger found at position: %d...\n", position);
                printf("Name: %s\nID: %d\n", current->passengerName, current->id);
                break;
            }
            current = current->next;
        }

        if (current == NULL) {
            printf("Passenger not found\n");
        }
    }
}

void removePassenger()
{
    int id;
    printf("Enter passenger ID to cancel booking: ");
    scanf("%d", &id);

    if (first == NULL) {
        printf("Passenger list is empty\n");
    } else {
        current = first;
        while (current != NULL && current->id != id) {
            current = current->next;
        }

        if (current == NULL) {
            printf("Cannot Cancel Booking, Passenger not found\n");
        } else {
            if (current == first && current == last) {
                first = NULL;
                last = NULL;
            } else if (current == first) {
                first = first->next;
                first->prev = NULL;
            } else if (current == last) {
                last = last->prev;
                last->next = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }

            free(current);
            printf("Booking Cancellation Successful\n");
        }
    }
}

void showForward()
{
    current = first;
    if (current == NULL) {
        printf("The Passenger list is empty\n");
        return;
    }

    printf("Displaying Passenger list from forward\n");
    while (current != NULL) {
        printf("ID = %d, Name: %s\n", current->id, current->passengerName);
        current = current->next;
    }
}

void showBackward()
{
    current = last;
    if (current == NULL) {
        printf("The Passenger list is empty\n");
        return;
    }

    printf("Displaying Passenger list from backward\n");
    while (current != NULL) {
        printf("ID = %d, Name: %s\n", current->id, current->passengerName);
        current = current->prev;
    }
}


void clearPassengers()
{
    while (first != NULL) {
        current = first;
        first = first->next;
        free(current);
    }
    last = NULL;
}

int main()
{
    int choice;
    int checkInType;

    while (1) {
        printf("\n---- SKYLINE AIRPORT ----\n");
        printf("1. Check-In Passenger\n");
        printf("2. Search Passenger\n");
        printf("3. Cancel Booking\n");
        printf("4. Show Passenger List (Forward)\n");
        printf("5. Show Passenger List (Backward)\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n1. Normal Check-In\n");
                printf("2. Priority Check-In (Elderly / Wheelchair Assistance / Business Class)\n");
                printf("Enter type of Check-In: ");
                scanf("%d", &checkInType);

                switch (checkInType) {
                    case 1: addPassenger(); break;
                    case 2: addPriorityPassenger(); break;
                    default: printf("Try Again\n");
                }
                break;

            case 2: findPassenger(); break;
            case 3: removePassenger(); break;
            case 4: showForward(); break;
            case 5: showBackward(); break;
            case 6:
                clearPassengers();
                printf("Thank you for using Skyline Airport System!\n");
                return 0;
            default: printf("Try Again!\n");
        }
    }
}
