#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue()
{   
    int x;
    printf("Enter element to insert: ");
    
    scanf("%d", &x);
    struct Node *ptr;
    
   
    ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = x;
    ptr->next = NULL;

    if(front == NULL)
    {
        front = rear = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }

    printf("%d inserted\n", x);
}

void dequeue()
{
    struct Node *temp;

    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    printf("%d deleted\n", front->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

void display()
{
    struct Node *temp;

    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    printf("Queue: ");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    int choice, x;

    while(1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}