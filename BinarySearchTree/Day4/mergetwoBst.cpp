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
        left=right=NULL;
    }
};

void inorder(Node* root, vector<int>&arr){
    if(root==NULL) return;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);

   
    return;

}

Node* buildTree(vector<int>&arr, int start, int end){
    if(start>end) return NULL;

    int mid = start+(end-start)/2;

    Node* root = new Node(arr[mid]);

    root->left=buildTree(arr, start, mid-1);
    root->right = buildTree(arr, mid+1, end);

    return root;
    
}

Node* mergeBst(Node* root1, Node* root2){
    vector<int>arr1;
    vector<int>arr2;

    inorder(root1, arr1);
    inorder(root2, arr2);

    // now here the merging steps for the array
    vector<int>finalarr;
    int i=0;
    int j=0;
    
    while(i<arr1.size() && j<arr2.size()){
        if(arr1[i]<arr2[j]){
            finalarr.push_back(arr1[i++]);
        }
        else{
            finalarr.push_back(arr2[j++]);
        }

    }

    while(i<arr1.size()){
        finalarr.push_back(arr1[i++]);
    }
    while(j<arr2.size()){
        finalarr.push_back(arr2[j++]);
    }


    // now here built the bst from the sorted arr
    return buildTree(finalarr,0, finalarr.size()-1);



}

void print(Node* root){
    if(root==NULL) return;

    print(root->left);
    cout<<root->data<<" ";
    print(root->right);


}

int main(){
    Node* root1= new Node(2);
    root1->left = new Node(1);
    root1->right = new Node(4);

    Node* root2 = new Node(9);
    root2->left=new Node(3);
    root2->right = new Node(12);


    Node* root = mergeBst(root1, root2);

    print(root);


}