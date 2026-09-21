#include<iostream>
#include<vector>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;

    node(int  val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
node* insert(node* root,int val){
    if(root == NULL){
        return new node(val);//new object node is created using node class
    }
    if(val < root->data){
        root->left = insert(root->left,val);
    }
    else{//val>root->data
        root->right = insert(root->right,val);
    }
    return root;
}
node* getInorderSuccessor(node* root){// to get the left most node in right subtree
    while(root != NULL && root->left != NULL){
        root = root->left;
    }
    return root;
}
node* del_node(node* root,int key){
   
    if(root == NULL){
        return NULL;
    }
    if(key < root->data){
        root->left = del_node(root->left,key);
    }
    else if(key > root->data){
        root->right = del_node(root->right,key);
    }
    else{
        if(root->left == NULL){//when one or no child
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL){//when one or no child
            node* temp = root->left;
            delete root;
            return temp;
        }
        else{//2children
            node* IS = getInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = del_node(root->right,IS->data);
        }
    }

    return root;
}

node* buildBST(vector<int> arr){
    node* root = NULL;

    for(int val:arr){
        root = insert(root,val);
    }
    return root;
}
bool Search(node* root,int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(key < root->data){
        return Search(root->left,key);
    }
    else{
        return Search(root->right,key);
    }
}
void inOrder(node* root){
    if(root == NULL)return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}


int main(){
    vector<int> arr = {3,2,1,5,6,4};//bst follows inorder
    node* root = buildBST(arr);
    inOrder(root);
    cout<<endl;
    cout<<Search(root,5);
    cout<<endl;

    insert(root,8);
    inOrder(root);

    del_node(root,8);
    cout<<endl;
    inOrder(root);
}