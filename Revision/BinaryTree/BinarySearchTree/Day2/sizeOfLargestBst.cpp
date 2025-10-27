#include<iostream>
#include<algorithm>
#include<climits>
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



class Info{
    public:
    int size;
    int min;
    int max;
    bool isBst;

    Info(int size, int min, int max, bool isBst){
        this->size = size;
        this->min=min;
        this->max = max;

        this->isBst=isBst;
    }

};


static int maxSize;
static int maxNode;

Info* sizeOfLargestBst(Node* root){

    if(root==NULL){
        return new Info( 0,  INT_MAX, INT_MIN,true);
    }

    Info* leftInfo = sizeOfLargestBst(root->left);
    Info* rightInfo = sizeOfLargestBst(root->right);

    int currentmin  =min(root->data, min(leftInfo->min, rightInfo->min));

    int currentmax = max(root->data, max(leftInfo->max, leftInfo->max));

    int currentSize = max(leftInfo->size, rightInfo->size)+1;

    if(leftInfo->isBst && rightInfo->isBst && root->data>leftInfo->max && root->data<rightInfo->min){
        maxSize=max(maxSize, currentSize);

        maxNode = max(maxNode, currentmax);
        return new Info(currentSize, currentmin, currentmax, true);
    }



    return new Info(currentSize, currentmin, currentmax,false );




}

int main(){

    Node* root = new Node(50);

    root->left = new Node(30);

    root->right = new Node(60);

    root->left->left = new Node(5);

    root->left->right = new Node(20);

    root->right->left = new Node(45);

    root->right->right= new Node(70);

    root->right->right->left= new Node(65);
    root->right->right->right = new Node(80);

    sizeOfLargestBst(root);


    cout<<maxSize<<endl<<maxNode;


}