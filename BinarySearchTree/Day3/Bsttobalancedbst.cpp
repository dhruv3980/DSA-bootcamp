#include<iostream>
#include<vector>
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

Node* buildBalancedfromvector(vector<int>&arr, int start, int end){
    if(start>end) return NULL;
    int mid = start+(end-start)/2;

    Node* currentNode = new Node(arr[mid]);
    currentNode->left = buildBalancedfromvector(arr, start, mid-1);
    currentNode->right = buildBalancedfromvector(arr, mid+1, end);
    return currentNode;

}

void storinvector(Node* root, vector<int>& arr){
    if(root==NULL) return;

    storinvector(root->left, arr);
    arr.push_back(root->data);
    storinvector(root->right, arr);
}

void print(Node* root){
    if(root==NULL) return;

    cout<<root->data<<" ";

    print(root->left);
    
    print(root->right);

}
int main(){
    Node* root = new Node(6);

    root->left = new Node(5);
    root->left->left=new Node(4);
    root->left->left->left = new Node(3);


    root->right = new Node(7);
    root->right->right=new Node(8);
    root->right->right->right = new Node(9);

    vector<int>arr;

    storinvector(root, arr);

    Node* root1 =buildBalancedfromvector(arr,0,arr.size()-1);

    print(root1);




}