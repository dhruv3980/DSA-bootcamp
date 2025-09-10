#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        left=right=NULL;
    }
};

Node* insert(Node* root, int val){
    if(root==NULL){
        return new Node(val);
    }

    if(root->data>val){
        root->left =  insert(root->left, val);

    }else{
        root->right= insert(root->right, val);
    }

    return root;

}
Node* generateBST(int arr[], int n){
    Node* root = NULL;

    for(int i=0; i<n; i++){
        root=insert(root, arr[i]);
    }
    return root;
}

void print(Node* root){
    if(root==NULL) return;

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}

void printinrange(Node*root, int start, int end){
    if(root==NULL) return;
    if(end>=root->data && root->data>=start){
        printinrange(root->left, start, end);
        cout<<root->data<<" ";
        printinrange(root->right, start, end);

    }
    else if(root->data<start){
        printinrange(root->right, start, end);
    }
    else if(root->data>end){
        printinrange(root->left,start, end);

    }
}
int main(){
    int arr[] = {8,5,10,3,6,1,4,11,14};
    int n=9;

    Node* root = generateBST(arr, n);

    print(root);
    cout<<endl;
    printinrange(root, 5,12);
}