#include<stdio.h>
#include<stdlib.h>

struct  Node
{
	int data;
	struct Node *link;
	
};
struct Node *front=NULL,*rear=NULL,*temp,*p,*ptr;

void enqueue()
{
	int x;
	printf("enter data to insert :");
	scanf("%d",&x);
	ptr= (struct Node*)malloc(sizeof(struct Node));
	ptr->data=x;
	ptr->link=NULL;
	if(front==NULL)
	{
		front=ptr;
		rear=ptr;
		rear->link=front; // in  circular queue rear connects to front//
	}
	else
	{
		rear->link=ptr;
		rear=ptr;
		rear->link=front ;// in circular queue is always repeats 
		
	}
	printf("inserted element is %d" ,x);
	
 } 
 
 void dequeue() // in dequeue we will handle 3 cases
 {
 	if(front==NULL) // case 1 : if queue is empty
 	{
 		printf("queue is empty ");
 		return;
 		
	 }
	 if(front==rear) // case 2 : if there is one element in the queue and it becomes front and rear
	 {
	 	printf("%d deleted ", front->data);
         temp=front; // we can write front->data or rear->data
	 	front= NULL;
	 	rear=NULL;
	 	free(temp);
	 	
	 }
	 else // case 3 : if more than one element is there (the main case )
	 { 
	 temp=front;
	 printf("%d deleted",front->data);
	 front=front->link;
	 rear->link=front; // connecting the circular loop from rear to  front after the dequeue
	 free(temp);
	 }
	 
 }
 void display()
{
    if(front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }

    temp = front;

    printf("Queue elements: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->link;
    } while(temp != front);

    printf("\n");
}
 
 int main()
 {
 	int choice;
 	while(1)
 	{
 		printf("\n 1.enqueue \n 2.dequeue \n 3.display \n 4.exit \n enter your choice :");
 		scanf("%d",&choice);
 		
 		switch(choice) // switch case starts here 
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
				 
			case  4:
			    exit(0);
				
			default:
			printf("invalid number ");		 		
		 }
	 }
	 return 0;
 }