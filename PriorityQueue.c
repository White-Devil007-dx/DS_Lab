#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data, priority;
    struct Node* link;
};

struct Node *front = NULL, *rear = NULL, *temp;

// Enqueue in arrival order (no priority logic here)
void enqueue() {
    int x, pri;
    printf("Enter data: ");
    scanf("%d", &x);
    printf("Enter Priority of data: ");
    scanf("%d", &pri);

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = x;
    ptr->priority = pri;
    ptr->link = NULL;

    if (front == NULL) {
        front = rear = ptr;
    } else {
        rear->link = ptr;
        rear = ptr;
    }
}

// Bubble sort the linked list by priority (lower = higher)
void bubbleSort() {
   if(front == NULL) return;
   int swapped;
   struct Node* ptr;
   ptr = front;

   do{
    swapped =0;
    while(ptr->link != NULL){
        if(ptr->priority > ptr->link->priority){
            int tempdata = ptr->data;
            int temppri = ptr->priority;

            ptr->data = ptr->link->data;
            ptr->priority = ptr->link->priority;

            ptr->link->data = tempdata;
            ptr->link->priority = temppri;

            swapped = 1;
        }
        ptr = ptr->link;
    }
   }while(swapped);

}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    temp = front;
    while (temp != NULL) {
        printf(" %d ", temp->data);
        temp = temp->link;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue underflow\n");
        return;
    }
    temp = front;
    printf("Dequeued element: Data = %d, Priority = %d\n", temp->data, temp->priority);
    front = front->link;
    free(temp);
}

int main(void) {
    int ch;
    while (1) {
        printf("\n1. Enqueue (arrival order)\n2. Display\n3. Sort by priority\n4. Dequeue highest priority\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: enqueue(); break;
            case 2: display(); break;
            case 3: bubbleSort(); printf("Queue sorted by priority.\n"); break;
            case 4: dequeue(); break;
            case 5: return 0;
            default: printf("Invalid Input\n");
        }
    }
}
