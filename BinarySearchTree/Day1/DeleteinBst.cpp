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
        root->left = insert(root->left, val);

    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

Node* generateBST(int arr[], int n){
    Node* root = NULL;

    for(int i=0; i<n; i++){
        root = insert(root, arr[i]);
    }



    return root;
}

void print(Node* root){
    if(root==NULL) return;

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);
}


Node* findinordersuccessor(Node* root){
    while(root->left!=NULL){
        return findinordersuccessor(root->left);
    }
    return root;

}


Node* deleteInBst(Node* root, int key){
    if(root==NULL) return NULL;

    if(root->data>key){
        root->left=deleteInBst(root->left, key);
    }
    else if(root->data<key){
        root->right = deleteInBst(root->right, key);
    }
    else{
        // i have 3 cases here 
        // ---> 1st one is when the it is the leaf node 
        if(root->left==NULL && root->right==NULL){
            delete(root);

            return NULL;
        }

        if(root->left==NULL || root->right==NULL){
            root=root->left==NULL? root->right:root->left;

            return root;
        }

        // 3rd cases when it have both the childer then find inorder successor and replace it with that node

        Node* is = findinordersuccessor(root->right);

        root->data = is->data;

        root->right = deleteInBst(root->right, is->data);
    }



    return root;
}
int main(){
    int arr[]={8,10,5,6,3,11,14,1,4};
    int n =9;

    Node* root = generateBST(arr, n);

    print(root);

    cout<<endl;


    Node* h =deleteInBst(root, 8);

    print(h);

}