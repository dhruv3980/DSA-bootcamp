// height of the tree
// sum of the Node
//count of Nodes

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node( int data){
        this->data = data;
        left = right = NULL;
    }

};


static int idx = -1;

Node* BuildTree(int arr[], int size){
    idx++;

    if(arr[idx]==-1){
        return NULL;
    }

    Node* currentNode = new Node(arr[idx]);

    currentNode->left = BuildTree(arr, size);
    currentNode->right =BuildTree(arr, size);

}


int heightOfTheTree(Node* root){

    if(root==NULL) return 0;


    int ans1 = heightOfTheTree(root->left);
    int ans2 = heightOfTheTree(root->right);

    return max(ans1, ans2)+1;
}

int coutOfNodes(Node* root){
    if(root==NULL) return 0;

    int leftNode = coutOfNodes(root->left);
    int rightNode = coutOfNodes(root->right);

    return leftNode+rightNode+1;
}

int sumOfNodes(Node* root){
    if(root==NULL) return 0;

    int leftNodeSum = sumOfNodes(root->left);
    int rightNodeSum = sumOfNodes(root->right);

    return leftNodeSum+rightNodeSum+root->data;

}
int main(){
    int arr[]={1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};
    int size = 15;

    Node* root=BuildTree(arr, size);

    cout<<heightOfTheTree(root);

    cout<<endl<<coutOfNodes(root);

    cout<<endl<<sumOfNodes(root);

}