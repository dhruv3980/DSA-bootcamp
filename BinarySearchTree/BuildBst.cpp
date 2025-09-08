#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        left = right = NULL;
    }
};

Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }
    if (value < root->val)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
};

Node *BST(int arr[], int n)  //O(nlogn) time complexity
{
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        root=insert(root, arr[i]);
    }
    return root;
}


void inordertraversal (Node* root){
    if(root==NULL) return;

    inordertraversal(root->left);
    cout<<root->val<<" ";
    inordertraversal(root->right);


    
}
int main()
{
    int arr[] = {5, 1, 3, 4, 2, 7};
    int n = 6;

    Node* root = BST(arr, n);

    inordertraversal(root);
}