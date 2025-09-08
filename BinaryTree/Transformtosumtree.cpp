#include <iostream>
#include <vector>
#include <queue>
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
        this->left = NULL;
        this->right = NULL;
    }
};

int idx = -1;
Node *buildTree(vector<int> &node)
{
    idx++;

    if (node[idx] == -1)
    {
        return NULL;
    }

    // make node
    Node *currentNode = new Node(node[idx]);

    currentNode->left = buildTree(node);
    currentNode->right = buildTree(node);

    return currentNode;
}

void printinglevelwise(Node *head)
{
    if (head == NULL)
        return;

    queue<Node *> q;

    q.push(head);
    q.push(NULL);

    while (!q.empty())
    {

        Node *current = q.front();
        q.pop();

        if (current == NULL)
        {
            cout << endl;
            if (q.empty())
            {
                break;
            }

            q.push(NULL);
        }
        else
        {
            cout << current->data << " ";

            if (current->left != NULL)
            {
                q.push(current->left);
            }
            if (current->right != NULL)
            {
                q.push(current->right);
            }
        }
    }
};

int transformtosum(Node* head){
    if(head==NULL) return 0;

    int leftsum = transformtosum(head->left);
    int rightsum = transformtosum(head->right);

    int currentval = head->data;

    head->data=leftsum+rightsum;

    return head->data+currentval;


    
}


int main()
{
    vector<int> head = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    Node *hea = buildTree(head);
    printinglevelwise(hea);

    cout << endl
         << "-------After------" << endl;

    int ans = transformtosum(hea);

    printinglevelwise(hea);
}