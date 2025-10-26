#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data= data;
        left=right=NULL;
    }
};

static int idx=-1;
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

void kthLevelOfTree(Node* root, int kthlevel , int k){
    if(root==NULL){
        return;
    }

    if(kthlevel==k){
        cout<<root->data<<" ";
    }

    kthLevelOfTree(root->left, kthlevel, k+1);
    kthLevelOfTree(root->right, kthlevel, k+1);



}
int main(){
    int arr[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int size = 13;

    Node* root =buildTree(arr, size);

    kthLevelOfTree(root, 3,1);
}