#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};

struct node *head,*tail = NULL,*temp,*ptr,*p;

void create(){
    int n,data;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    for(int i= 1;i<=n;i++){
        ptr = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d",&data);
        ptr->data = data;
        ptr->left = NULL;
        ptr->right = NULL;
        if(head == NULL){
            head = ptr;
            tail = ptr;

        head->left = tail;
        head->right = head;

        }
        else{ 
            ptr->left = tail;
            ptr->right = head;

            tail->right = ptr;
            head->left = tail;

            tail = ptr;


        }
    }
}

void ins_begin(){
    int data;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data :");
    scanf("%d",&data);
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;

    if(head == NULL){
        head = ptr;
        tail = ptr;
        head->right = tail;
        head->left = head;
    }
    else{
        head->left = ptr;
        ptr->right = head;

        ptr->left = tail;
        tail->right = ptr;

        head = ptr;

    }
}

void ins_end(){
    int data;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
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

        ptr->right = head;
        head->left = ptr;
        
        tail = ptr;

    }

}

void ins_middle(){
    int n,data;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter the position :");
    scanf("%d",&n);
    printf("Enter the data :");
    scanf("%d",&data);
    ptr->data = data;
    ptr->left = NULL;
    ptr->right = NULL;

   
    temp = head;
    for(int i = 1;i<n;i++){
        p = temp;
        temp = temp->right;
    }

    ptr->left = p;
    p->right = ptr;

    ptr->right = temp;
    temp->left = ptr;

}

void del_begin(){
    if(head == NULL){
        printf("Deletion not possible");
    }
    else{
        temp = head;
        tail->right = temp->right;
        temp->right->left = tail;
        head = temp->right;
        free(temp);
        temp = NULL;
    }
}

void del_end(){
    if(tail == NULL){
        printf("deletion not possible");
    }
    else{
        temp = tail;
        head->left = temp->left;
        temp->left->right = head;
        tail = temp->left;
        free(temp);
        temp = NULL;
    }
}

void del_middle(){
    int n;
    printf("Enter the position:");
    scanf("%d",&n);
    temp = head;
    for(int i = 1;i<n;i++){
        p = temp;
        temp = temp->right;
    }
    p->right = temp->right;
    temp->right->left = p->left;
    free(temp);
    temp =NULL;
}

void display(){
    if(head == NULL){
        printf("No data");
    }
    else{
        temp = head;
        do{
            printf("%d->",temp->data);
            temp = temp->right;
        }
        while(temp != head);
        printf("(head)");
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
                printf("\nProgram Terminated.");
                exit(0);

            default:
                printf("\nInvalid Choice.");
        }
    }

    return 0;
}
