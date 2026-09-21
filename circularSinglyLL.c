#include<stdio.h>
#include<stdlib.h>
struct node{ 
	int data;
	struct node *link;
};
struct node *ptr,*head=NULL,*tail=NULL,*p,*q,*temp;
void create()
{
	int data,i,n;
	printf("enter number of nodes:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		ptr=(struct node*) malloc(sizeof ( struct node ) );
		printf("enter the data:");
		scanf("%d",&data);
		ptr->data=data;
		ptr->link=NULL;
		if(head==NULL){
			head=ptr;
			tail=ptr;
		}
		else{
			tail->link=ptr;
			ptr->link=head;
			tail=ptr;
		}
		}
}
void ins_begin()
{
int data;
ptr=(struct node*) malloc(sizeof (struct node));
printf("enter data to insert");
scanf("%d",&data);
ptr->data=data;
ptr->link=NULL;
if(head==NULL)
{
	head=ptr;
	tail=ptr;
}
else
{
	ptr->link=head;
	tail->link=ptr;
	head=ptr;
}
}
void ins_end()
{
	int data;
    ptr=(struct node*) malloc(sizeof (struct node));
    printf("enter data to insert");
    scanf("%d",&data);
    ptr->data=data;
    ptr->link=NULL;
    if(head==NULL){
    	head=ptr;
    	tail=ptr;
	}
	else{
		tail->link=ptr;
		ptr->link=head;
		tail=ptr;
	}
}
void ins_middle()
{
	int data,pos,i = 1;
    ptr=(struct node*) malloc(sizeof (struct node));
    printf("enter data to insert");
    scanf("%d",&data);
    ptr->data=data;
    ptr->link=NULL;
    printf("enter postion to insert");
    scanf("%d",&pos);
    temp=head;
    while(i<pos)
    {
    	p=temp;
    	temp=temp->link;
    	i++;
	}
	p->link=ptr;
	ptr->link=temp;
}
void del_begin()
{
    if(head==NULL){
    	printf("no data to delete");
}
else{
	p=head;
	head=head->link;
	tail->link=head;
	free(p);
}
}
void del_end()
{
	if(head==NULL){
		printf("no data to delete");
	}
	else{
		temp=head;
		while(temp->link!=head){
			p=temp;
			temp=temp->link;
		}
		free(temp);
		p->link=head;
		tail=p;
	}
}
void del_middle()
{
	int i=1,pos;
    printf("enter postion to delete");
    scanf("%d",&pos);
    temp=head;
    while(i<pos){
    	p=temp;
    	temp=temp->link;
    	p->link=temp->link;
    	i++;
	}
    free(temp);
}
void display()
{
    if(head==NULL)
	{
    	printf("no data to display");
	}
	else if(head->link==head){
		printf("%d\t",head->data);
	}else{
		printf("\nlinked list : ");
		temp=head;
		do{
			printf(" %d ",temp->data);
			temp=temp->link;
		}
		while(temp!=head);
}
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
		printf("\n5. Exit");
		
		printf("\nenter your choice :");
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
		    	printf("\n\n---- INSERT MENU ----");
		    	printf("\n1. beginning");
		    	printf("\n2. middle");
		    	printf("\n3. end");
		    	
		    	printf("\nenter  your choice");
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
		    			printf("Invaild Choice");
		    }
		    break;
		    
		case 4:
			printf("\n\n---- DELETE MENU----");
			printf("\n1. Beginning");
			printf("\n2. middle");
			printf("\n3. end");
			
			printf("\nenter your choice : ");
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
					printf("Invaid choice");
		}
		break;
		
	case 5:
		printf("\nprogram terminated.");
		exit(0);
		
	default:
		printf("\nInvaild choice");
	}
}
return 0;
}
