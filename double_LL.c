#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
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
	ptr->left = NULL;
	ptr->right = NULL;
	if(head ==NULL){
		head = ptr;
		tail = ptr;
        head->right = tail;
        tail->left = head;
	}
	else{
		tail->right =ptr;
		ptr->left = tail;
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
	ptr->left = NULL;
	ptr->right = NULL;
	if(head ==NULL){
		head = ptr;
		tail = ptr;
	}
	else{
		ptr->right = head;
		head->left = ptr;
		head = ptr;
	}
}

void ins_end(){
	int data;
	ptr = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data to insert");
	scanf("%d",&data);
	ptr->data = data;
	ptr->left = NULL;
	ptr->right = NULL;
	if(tail == NULL){
		head = ptr;
		tail = ptr;
	}
	else{
		tail->right = ptr;
		ptr->left = tail;
		tail = ptr;
	}
}

void ins_middle(){
    int data, n;
    ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data to insert: ");
    scanf("%d", &data);
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;

    printf("Enter the position to insert: ");
    scanf("%d", &n);


    temp = head;
    for (int i = 1; i < n ; i++) {
        p = temp;
        temp = temp->right;
    }

    p->right = ptr;
    ptr->left = p;
    ptr->right = temp;
    temp->left = ptr;
}


void del_begin(){
	
	
	if(head == NULL){
		printf("Deletion not possible");
	}
	else{
		p = head;
		head = head->right;
		if(head != NULL){
			head->left = NULL;
		}
		else{
			tail = NULL;
		}
		free(p);
		
	}
}

void del_end(){
	
	if(head == NULL){
		printf("Deletion not possible");
	}
	else if(head->right == NULL){
		free(head);
		head = NULL;
		tail = NULL;
	}
	else{
		temp = tail;
		tail = tail->left;
		tail->right = NULL;
		free(temp);
	}
	
}

void del_middle(){
    int n;
    printf("Enter the position: ");
    scanf("%d", &n);

    if (head == NULL) {
        printf("Deletion not possible\n");
        return;
    }

    if (n <= 1) {
        del_begin();
        return;
    }

    temp = head;
    for (int i = 1; i < n && temp != NULL; i++) {
        p = temp;
        temp = temp->right;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    p->right = temp->right;
    if (temp->right != NULL) {
        temp->right->left = p;
    } else {
        tail = p;  // deleted last node → update tail
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
			temp = temp->right;
		}
		printf("NULL\n");
	}
}

void reverse(){
    next = NULL;
    p = NULL;
    temp = head;

    while (temp != NULL) {
        next = temp->right;
        temp->right = p;
        temp->left = next;
        p = temp;
        temp = next;
    }

    // after reversal, p is new head
    tail = head;
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