#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// build binary tree using preorder of the tree

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

};
int idx=-1;
Node* buildTree(vector<int>&node){
    idx++;

    if(node[idx]==-1){
        return NULL;
    }

    // make node
    Node* currentNode = new Node(node[idx]);

    currentNode->left = buildTree(node);
    currentNode->right = buildTree(node);

    return currentNode;



}

// all of three dfs technique

void preOrderTraversal(Node* head){ // in preordertraversal first root print then left subtree and right subtree

    if(head==NULL) return;

    cout<< head->data<<" ";

    preOrderTraversal(head->left); // left subtree

    preOrderTraversal(head->right); //rightsubtree

}

void inOrderTraversal(Node* head){ // in this first leftsubtree print then root node print then rightsubtree node

    if(head==NULL) return;

    inOrderTraversal(head->left); // left subtree

    cout<<head->data<<" ";

    inOrderTraversal(head->right); // right subtree

}

void postOrderTraversal(Node* head){ // in this first print left subtree and then right subtree at last print root data

    if(head==NULL) return;

    postOrderTraversal(head->left); // keft subtree

    postOrderTraversal(head->right); // right subtree

    cout<<head->data<<" ";

}


void levelOrderTraversal(Node* head){ //simple order level order traversal

    if(head==NULL) return;
    queue<Node*> q;

    q.push(head);
    

    while(!q.empty()){
        // in this first print the data
       Node* current = q.front();

       q.pop();

       cout<<current->data<<" ";

       // now here we enter the left child value and right child value on the next level in the queue

       if(current->left!=NULL){
        q.push(current->left);
       }

       if(current->right!=NULL){

        q.push(current->right);
       }



    }
    

}


void modifyLevelOrderTraversal(Node* head){
    queue<Node*> q;

    q.push(head);
    q.push(NULL);

    while(!q.empty()){
        Node* current = q.front();

        q.pop();
        if(q.empty()){
                break;
        }

        if(current==NULL){
            cout<<endl;
            

            q.push(NULL);
        }
        else{
            cout<<current->data<<" ";

            if(current->left!=NULL){
                q.push(current->left);
            }

            if(current->right!=NULL){
                q.push(current->right);
            }
        }
    }
}

int main(){
    vector<int>node{1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* head = buildTree(node);

    cout<<"the current head  value is "<<head->data;

    cout<<endl;

    cout<<"print pre order traversal"<<endl;

    preOrderTraversal(head);

    cout<<endl<<"Print the inorder traversal"<<endl;

    inOrderTraversal(head);

    cout<<endl<<"Print the postorder traversal "<<endl;

    postOrderTraversal(head);

    cout<<endl<<"Printing the level order traversal"<<endl;

    levelOrderTraversal(head);

    cout<<endl<<"Printing Modify level Order traversal "<<endl;

    modifyLevelOrderTraversal(head);


}