#include <iostream>
#include <vector>
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

Node *insert(Node *root, int value)
{
    if (root == NULL)
        return new Node(value);

    if (root->data > value)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }

    return root;
}

Node *generateBST(int arr[], int n)
{
    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }

    return root;
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void roottoleft(Node *root, vector<int> &arr)
{

    if (root == NULL)
    {

        return;
    }
    arr.push_back(root->data);
    if(root->left==NULL && root->right==NULL){
        print(arr);
        arr.pop_back();
        return;

    }
    roottoleft(root->left, arr);
    roottoleft(root->right, arr);

    arr.pop_back();
    return;
}
int main()
{
    int arr[] = {8, 5, 10, 3, 6, 1, 4, 11, 14};
    int n = 9;

    Node *root = generateBST(arr, n);
    vector<int> arr2;

    roottoleft(root, arr2);
}