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

static int idx = -1;

node* buildTree(vector<int> preorderArray){

idx++;
if(preorderArray[idx] == -1)return NULL;
node *root = new node(preorderArray[idx]);
root->left = buildTree(preorderArray);  
root->right = buildTree(preorderArray);
return root;
}

void preOrder(node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(node *root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
void inOrder(node *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
int main(){
    vector<int> preorderArray = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    node *root = buildTree(preorderArray);
    preOrder(root);
    cout<<"\n";
    postOrder(root);
    cout<<"\n";
    inOrder(root);
    cout<<"\n";
}

