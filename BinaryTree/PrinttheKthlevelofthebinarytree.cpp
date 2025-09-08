#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data= data;
        this->left=NULL;
        this->right= NULL;
    }
};
int idx=-1;
Node* createTree(vector<int>&arr){
    if(arr.size()==0) return NULL;
    idx++;

    if(arr[idx]==-1) return NULL;

    Node* head = new Node(arr[idx]);
    head->left = createTree(arr);
    head->right = createTree(arr);

    return head;

};

void printthetree(Node* head, int kthlevel){
    int count =0;
    if(head==NULL) return;

    queue<Node*>q;
    q.push(head);
    q.push(NULL);

    while(!q.empty()){
        Node* currentNode = q.front();

        q.pop();

       
       

        if(currentNode==NULL){
            cout<<endl;

             count++;

              

             
            if(!q.empty()){
                q.push(NULL);

            }
            
        }
        else{
           
            if(count+1==kthlevel){
                cout<<currentNode->data<<" ";
            }
            
            if(currentNode->left!=NULL){
                q.push(currentNode->left);
            }
            
            if(currentNode->right!=NULL){
                q.push(currentNode->right);

            }
            
        }
        
    }
}


void printthekthlevel(Node* head, int currentlevel, int kthlevel){
    if(head==NULL) return;

    if(currentlevel ==kthlevel){
        cout<<head->data<<" ";
        return;
    }

    printthekthlevel(head->left, currentlevel+1, kthlevel);
    printthekthlevel(head->right, currentlevel+1, kthlevel);
}
int main(){
    vector<int> arr ={1,2,4,-1,-1,5,-1,-1, 3,-1, 6,-1, -1};

    Node* head = createTree(arr);

    printthetree(head, 3);

    printthekthlevel(head,1,3);
}