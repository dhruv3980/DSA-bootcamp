#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* left;
    Node* right;

    Node(int data){
        this->val = data;
        left=right=NULL;
    }

};

Node* insert(Node* root, int val){
    if(root==NULL) {
        return new Node(val);
    }

    if(root->val>val){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
}

Node* generateBst(int arr[], int n){
    Node* root = NULL;

    for(int i=0; i<n; i++){

        root=insert(root, arr[i]);

    }

    return root;
};

void print(Node* root){
    if(root==NULL) return;

    print(root->left);
    cout<<root->val<<" ";
    print(root->right);

}

bool serarchinBst(Node* root, int key){
    if(root==NULL) return false;

    if(root->val==key) return true;

    if(root->val>key){
        return serarchinBst(root->left, key);
    }
    else{
        return serarchinBst(root->right, key);
    }
}
int main(){
    int arr[]={8,5,10,3,6,1,4,11,14};
    int n = 9;

    Node* root = generateBst(arr, n);

    print(root);
    cout<<endl;

    cout<<serarchinBst(root, 15);


}