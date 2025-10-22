#include<iostream>
#include<queue>
using namespace std;

static int idx =-1;

class Node{
    public:
    int data;
    Node* leftChild;
    Node* rightChild;

    Node(int data){
        this->data = data;
        leftChild=rightChild=NULL;
    }
};

Node* buildTreeFromPreOrder(int arr[], int size){
    idx++;


    int currentdata=arr[idx];
    if(currentdata==-1){
        return NULL;
    }
    Node* newNode = new Node(currentdata);
    newNode->leftChild = buildTreeFromPreOrder(arr, size);
    newNode->rightChild = buildTreeFromPreOrder(arr, size);

    return newNode;



}

void PreorderTraversal(Node* root){
    if(root==NULL){
        
        return;
    }

    cout<<root->data<<" ";
    PreorderTraversal(root->leftChild);
    PreorderTraversal(root->rightChild);
}

void inOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }

    inOrderTraversal(root->leftChild);
    cout<<root->data<<" ";
    inOrderTraversal(root->rightChild);
}

void postOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }

    postOrderTraversal(root->leftChild);
    postOrderTraversal(root->rightChild);
    cout<<root->data<<" ";
}

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* currentNode = q.front();

        if(currentNode==NULL){
            q.pop();

            if(q.empty()){
                break;

            }

            cout<<endl;
            q.push(NULL);
        }
        else {

            cout<<currentNode->data<<" ";
            if(currentNode->leftChild!=NULL){
                q.push(currentNode->leftChild);
            }
            if(currentNode->rightChild!=NULL){
                q.push(currentNode->rightChild);
            }

            q.pop();


        }
       

    }

}
int main(){
    int arr[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int size = 13; 

    Node* root = buildTreeFromPreOrder(arr, size);

   PreorderTraversal(root);

   cout<<endl;

   inOrderTraversal(root);
   cout<<endl;
   postOrderTraversal(root);

   cout<<endl;
   levelOrderTraversal(root);
}