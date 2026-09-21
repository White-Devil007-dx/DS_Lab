#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *tail,*head = NULL,*ptr,*temp, *p,*next;

void create(){
	int data,n;
	printf("Enter the no. of nodes:");
	scanf("%d",&n);

	for(int i = 1;i<=n;i++){
		ptr = (struct node*)malloc(sizeof(struct node));
		printf("Enter the data:");
		scanf("%d",&data);

		ptr->data = data;
		ptr->link = NULL;

		if(head == NULL){
			head = ptr;
			tail = ptr;
			
		}
		else{
			tail->link = ptr;
			tail = ptr;
			
		}
	}
}

void ins_begin(){
	int data;
	ptr =(struct node*)malloc(sizeof(struct node));
	printf("Enter the data to insert");
	scanf("%d",&data);

	ptr->data = data;
	ptr->link = NULL;

	if(head == NULL){
		head = ptr;
		tail = ptr;
		tail->link = head;
	}
	else{
		ptr->link = head;
		head = ptr;
		tail->link = head;
	}
}

void ins_end(){
	int data;
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data to insert");
	scanf("%d",&data);

	ptr->data = data;
	ptr->link = NULL;

	if(tail == NULL){
		head = ptr;
		tail = ptr;
		tail->link = head;
	}
	else{
		tail->link = ptr;
		tail = ptr;
		tail->link = head;
	}
}

void ins_middle(){
	int data,n;
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data to insert");
	scanf("%d",&data);

	ptr->data = data;
	ptr->link = NULL;

	printf("Enter the position to insert");
	scanf("%d",&n);


	temp = head;
	for(int i = 1;i<n;i++){
		p = temp;
		temp = temp->link;

	}

	p->link = ptr;
	ptr->link = temp;

	
}

void del_begin(){
	if(head == NULL){
		printf("Deletion not possible");
	}
	else if(head == tail){
		p = head;
		head = NULL;
		tail = NULL;
		free(p);
	}
	else{
		p = head;
		head = head->link;
		tail->link = head;
		free(p);
	}
}

void del_end(){
	if(head == NULL){
		printf("Deletion not possible");
	}
	else{
		temp = head;
		while(temp->link != NULL){
			p = temp;
			temp = temp->link;
		}
		p->link = NULL;
		free(temp);
		tail = p;
	}
}

void del_middle(){
	int n;
	printf("Enter the position:");
	scanf("%d",&n);

	if(head == NULL){
		printf("Deletion not possible");
		return;
	}

	if(n<=1){
		del_begin();
		return;
	}

	temp = head;
	for(int i = 1;i<n;i++){
		p = temp;
		temp = temp->link;

		if(temp == head){
			printf("Position not found");
			return;
		}
	}

	p->link = temp->link;

	if(temp == tail){
		tail = p;
	}

	free(temp);
	temp = NULL;
}

void display(){
	if(head == NULL){
		printf("No data");
	}
	else{
		temp = head;
		while(temp != NULL){
			printf("%d->",temp->data);
			temp = temp->link;
		}
		printf("NULL");
	}
}

void reverse(){
	if(head == NULL){
		printf("No data");
		return;
	}
	next = NULL;
	p = tail;
	temp = head;
	tail = head;

	do{
		next = temp->link;
		temp->link = p;
		p = temp;
		temp = next;
	}while(temp != head);

	head = p;
}

int main()
{
	int ch,sub;
	while(1)
	{
		printf("\n\n========= MENU =========");
		printf("\n1. Create");
		printf("\n2. Display");
		printf("\n3. Insert");
		printf("\n4. Delete");
		printf("\n5. Reverse");
		printf("\n6. Exit");

		printf("\nEnter your choice : ");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				create();
				break;

			case 2:
				display();
				break;

			case 3:
				printf("\n\n----- INSERT MENU -----");
				printf("\n1. Beginning");
				printf("\n2. Middle");
				printf("\n3. End");

				printf("\nEnter your choice : ");
				scanf("%d",&sub);

				switch(sub)
				{
					case 1:
						ins_begin();
						break;

					case 2:
						ins_middle();
						break;

					case 3:
						ins_end();
						break;

					default:
						printf("Invalid Choice");
				}
				break;

			case 4:
				printf("\n\n----- DELETE MENU -----");
				printf("\n1. Beginning");
				printf("\n2. Middle");
				printf("\n3. End");

				printf("\nEnter your choice : ");
				scanf("%d",&sub);

				switch(sub)
				{
					case 1:
						del_begin();
						break;

					case 2:
						del_middle();
						break;

					case 3:
						del_end();
						break;

					default:
						printf("Invalid Choice");
				}
				break;

			case 5:
				reverse();
				break;

			case 6:
				printf("\nProgram Terminated.");
				exit(0);

			default:
				printf("\nInvalid Choice.");
		}
	}

	return 0;
}