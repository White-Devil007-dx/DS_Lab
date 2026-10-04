#include<stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

Node* create(int val){
    Node* root = (Node*)malloc(sizeof(Node));
    root->data = val;
    root->left = NULL;
    root->right = NULL;
    return root;
}

Node* insert(Node* root, int val){
    if(root == NULL){
    return create(val);
    }
    if(root->data > val){
        root->left = insert(root->left,val);
    }
    else if(root->data < val){
        root->right = insert(root->right,val);
    }
    else{   // if (root->data == val)
        root->data = val;
    }
    return root;
}

Node* buildBST(int arr[],int sz){
    Node* root = NULL;
    for(int i = 0;i<sz;i++){
        root = insert(root,arr[i]);
    }
    return root;
}

void preorder(Node* root){
    if(root == NULL) return;
    else{
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
       
    }
}

void inorder(Node* root){
    if(root == NULL) return;
    else{
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(Node* root){
    if(root == NULL) return;
    else{
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

bool search(Node* root,int key){
if(root == NULL){
    return false;
}
if(root->data == key){
    return true;
}
if(root->data <key){
    return search(root->right,key);
}
else{
    return search(root->left,key);
}

}

int main(){
    int arr[] = {21,24,34,22,26,22,34,21};
    int sz = sizeof(arr)/sizeof(arr[0]);
    Node* root = buildBST(arr,sz);

    printf("Inorder:");
    inorder(root);
    printf("\n");

    printf("Preorder:");
    preorder(root);
    printf("\n");
    
    printf("postorder:");
    postorder(root);
    printf("\n");


    if(!search(root,26)){
        printf("Not Found");
    }
    else{
        printf("Found");
    }
}