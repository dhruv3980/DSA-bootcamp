#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left = NULL;
        this->right = NULL;
    }
};

static int idx =-1;
Node* buildTree(int arr[]){
    idx++;

    if(arr[idx]==-1){
        return NULL;
    }

    Node* root = new Node(arr[idx]);

    root->left = buildTree(arr);
    root->right = buildTree(arr);


    return root;

}

int transformtosumtree(Node* root){
    if(root==NULL) return 0;

   
    int leftold = transformtosumtree(root->left);
    int rightold = transformtosumtree(root->right);
    int currentold = root->data;

    root->data = leftold+rightold;

    if(root->left!=NULL){
        root->data+=root->left->data;
    }
    if(root->right!=NULL){
        root->data+=root->right->data;
    }




    return currentold;


}

void printTree(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* currentNode = q.front();
        q.pop();

        if(currentNode==NULL){
            cout<<endl;
            if(q.empty()){
                break;

            }

            q.push(NULL);
        }
        
        else{
 
            cout<<currentNode->data<<" ";

             if(currentNode->left!=NULL){
                q.push(currentNode->left);


            }

            if(currentNode->right!=NULL){
                q.push(currentNode->right);
            }
        }
    }


}

int main(){
    int arr[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int size =13;


    Node* root = buildTree(arr);

    transformtosumtree(root);

    printTree(root);


   

   
}