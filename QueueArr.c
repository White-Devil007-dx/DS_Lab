#include<stdio.h>
#include<stdlib.h>

int queue[5];
int front = -1, rear = -1, data;

void enqueue();
void dequeue();
void display();

void enqueue() {
    if (rear == 4) {
        printf("The queue is full!!!!\n");
    }
    else {
        printf("Enter the data to insert: ");
        scanf("%d", &data);
        
        if (front == -1) {
            front = 0;
        }
        
        rear++;
        queue[rear] = data;
        printf("Inserted %d successfully.\n", data);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!!!!\n");
    }
    else {
        printf("Deleted item is %d\n", queue[front]);
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!!!!\n");
        return;
    }
    else {
        printf("Queue elements are: ");
        
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int ch;
    
    do {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter Your Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
                    printf("Program Terminated");
                    break;
            default: printf("Invalid choice!!!\n");
                    break;
        }
    } while(1);
    
    return 0;
}
