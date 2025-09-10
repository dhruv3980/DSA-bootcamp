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

Node* buildBST(int arr[], int start, int end){
    if(start>end) return NULL;
    
    int mid = start+(end-start)/2;
    Node* current = new Node(arr[mid]);
    current->left = buildBST(arr, start, mid-1);
    current->right =buildBST(arr, mid+1, end);

}

void printBSt(Node* root){
    if(root==NULL) return;

    printBSt(root->left);
    
    printBSt(root->right);
    cout<<root->data<<" ";

    
}
int main(){
    int arr[]={3,4,5,6,7,8,9};

    Node* root = buildBST(arr,0, 6 );
    printBSt(root);


}