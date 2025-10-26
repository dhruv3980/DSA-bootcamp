#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left = NULL;
        this->right = NULL;
    }
};

static int idx =-1;
Node* buildTree(int arr[], int size){
    idx++;

    if(arr[idx]==-1){
        return NULL;
    }

    Node* root = new Node(arr[idx]);

    root->left = buildTree(arr, size);
    root->right = buildTree(arr, size);


    return root;

}


int helper(Node* root, int node, int k){
    if(root==NULL)  return -1;

    if(root->data==node){
        return 0;
    }

    int leftans= helper(root->left, node, k);

    if(leftans!=-1){
        if(leftans+1==k){
            cout<<root->data;
        }
        return leftans+1;
    }
    int rightans = helper(root->right, node, k);
    if(rightans!=-1){
        if(rightans+1==k){
            cout<<root->data;
        }
        return rightans+1;
    }

    return -1;



}

int main(){
    int arr[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int size =13;


    Node* root = buildTree(arr, size);

    helper(root, 3, 1);

   
}