#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left ;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

int idx=-1;

Node* generateTree(vector<int>&arr){
    idx++;
    if(arr[idx]==-1){
        return NULL;
    }

    Node* head = new Node(arr[idx]);
    head->left = generateTree(arr);
    head->right=generateTree(arr);

    return head;
}

int kthancestor(Node* head, int node, int k){
    if(head==NULL) return -1;

    if(head->data==node) {
        return 0;

    }

    int leftans = kthancestor(head->left, node, k);

    int rightans = kthancestor(head->right, node, k);

    if(leftans==-1 && rightans==-1){
        return -1;
    }

    int val = leftans==-1? rightans:leftans;

    if(val+1==k){
        cout<<"kth ancestor is "<<head->data;
    }

    return val+1;
}

int main(){
    vector<int>head = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};

    Node* headq = generateTree(head);
    kthancestor(headq, 5, 2);


}