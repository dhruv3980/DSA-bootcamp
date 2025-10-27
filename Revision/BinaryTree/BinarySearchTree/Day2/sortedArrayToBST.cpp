#include<iostream>
#include<vector>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right ;

    Node(int data){
        this->data = data;
        left=right =NULL;

    }
};

Node* treeHelper(int arr[], int start, int end){
    if(start>end){
        return NULL;
    }
    int mid = start+(end-start)/2;

    Node* root = new Node(arr[mid]);

   root->left= treeHelper(arr, start, mid-1);

   root->right = treeHelper(arr, mid+1, end);


   return root;

}

Node* buildTree(int arr[], int size){

    return treeHelper(arr, 0, size-1);

}


void printTree(Node* root){
    if(root==NULL) return;

    printTree(root->left);

    cout<<root->data<<" ";

    printTree(root->right);
}

void inOrderSuccessor(Node* root, vector<int>& arr){
    if(root==NULL) return;

    inOrderSuccessor(root->left, arr);
    arr.push_back(root->data);
    inOrderSuccessor(root->right, arr);
}


Node* BuildTree(vector<int>arr, int start, int end){


    if(start>end) return NULL;
        int mid=start+(end-start)/2;

    Node* root= new Node(arr[mid]);

    root->left=BuildTree(arr, start, mid-1);

    root->right = BuildTree(arr, mid+1, end);

    return root;


}
Node* converBSTToBALANCEDBST(Node* root){
    vector<int> arr;
    inOrderSuccessor(root, arr);



    // now make tree from array and return

    return BuildTree(arr, 0, arr.size()-1);
}
int main(){
    int arr[]={3,4,5,6,7,8,9};
    int size=7;

    Node* root = buildTree(arr, size);

    printTree(root);

    cout<<endl;


    Node* root1=new Node(6);

    root1->left=new Node(5);
    root1->left->left=new Node(4);
    root1->left->left->left=new Node(3);

    root1->right = new Node(7);

    root1->right->right = new Node(8);
    root1->right->right->right = new Node(9);

 


    Node* BalancedBst = converBSTToBALANCEDBST(root1);
   

    printTree(BalancedBst);
    
    

}