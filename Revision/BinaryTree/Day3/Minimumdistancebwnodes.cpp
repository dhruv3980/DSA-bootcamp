#include<iostream>
#include<vector>
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

Node* lca(Node* root, int n1, int n2){
    if(root==NULL) return NULL;

    if(root->data==n1 || root->data==n2){
        return root;
    }

    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);

    if(left!=NULL && right!=NULL){
        return root;


    }

    if(left!=NULL&& right==NULL){

        return left;

    }

    if(right!=NULL && left==NULL){
        return right;
    }

    if(left==NULL && right==NULL){
        return NULL;
    }
}


int distance(Node* root, int n1){
    if(root==NULL) return -1;
    if(root->data==n1){
        return 0;
    }

    int left = distance(root->left, n1);
    if(left==-1){
        int right = distance(root->right, n1);

        if(right!=-1){
            return right+1;

        }

        return -1;

    }


   
    return left+1;



}


int minimumdistance(Node* root , int n1, int n2){
    Node* common = lca(root, n1, n2);

    

    int leftpathdistance =distance(common, n1);

    
    
    int rightpathdistance=distance(common, n2);

  

    return leftpathdistance+rightpathdistance;
}
int main(){
    int arr[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int size =13;


    Node* root = buildTree(arr, size);


    cout<<minimumdistance(root,4,3);
}