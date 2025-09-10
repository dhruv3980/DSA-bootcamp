#include <iostream>
#include <climits>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

class info
{

public:
    int min;
    int max;
    bool isBst;
    int size;

    info(int min, int max, bool isBst, int size)
    {
        this->min = min;
        this->max = max;
        this->isBst = isBst;
        this->size = size;
    }
};

int maxvalue;

info* largetstBSTinBST(Node* root){
    if(root==NULL){
        return new info(INT_MAX, INT_MIN, true, 0);
    }

    info* leftans =largetstBSTinBST(root->left);
    info* rightans = largetstBSTinBST(root->right);

    int currentmin = min(root->data, min(leftans->min, rightans->min));
    int currentmax = max(root->data, max(leftans->max, rightans->max));

    int currentsize = leftans->size + rightans->size+1;


    

    if(leftans->isBst && rightans->isBst && root->data>leftans->max && root->data<rightans->min){
        maxvalue = max(maxvalue, currentsize);
        return new info(currentmin, currentmax, true, currentsize);
    }
    return new info(currentmin, currentmax, false, currentsize);
}

int main()
{
    Node *root = new Node(50);

    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);

    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->right = new Node(80);
    root->right->right->left = new Node(65);


    largetstBSTinBST(root);

    cout<<"Largest Bst in the given Bst is "<<maxvalue;
}