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
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

    
};
int idx=-1;
Node* generateTree(vector<int>&head){

    idx++;

    if(head[idx]==-1){
        return NULL;
    }

    Node* currentNode = new Node(head[idx]);

    currentNode->left = generateTree(head);

    currentNode->right = generateTree(head);

    return currentNode;
    

}

void inordertraversal(Node* head){
    if(head==NULL){
        return;
    }

    cout<<head->data;

    inordertraversal(head->left);

    inordertraversal(head->right);

}


void printinglevelwise(Node* head){
    if(head==NULL) return;

    queue<Node*>q;

    q.push(head);
    q.push(NULL);
    
    int height=0;

    while(!q.empty()){
        // here first we remove element if currentelement is NULL then prind endline else print data
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
            height++;

            if(current->left!=NULL){
                q.push(current->left);
            }
            if(current->right!=NULL){
                q.push(current->right);
            }

        }

    }

    

    
    
       

};


int returnheightofthetree(Node* head){
    if(head==NULL) return 0;

    int leftans = returnheightofthetree(head->left);
    int rightans = returnheightofthetree(head->right);

    int currentheight = max(leftans, rightans)+1;
    
    return currentheight;
}

int coutthenoofNode(Node* head){
    if(head==NULL) return 0;

    int leftans = coutthenoofNode(head->left);
    int rightans = coutthenoofNode(head->right);

    return leftans+rightans+1;

}

int sumofNode(Node* head){
    if(head==NULL) return 0;

    int leftans = sumofNode(head->left);
    int rightans = sumofNode(head->right);

    return leftans+rightans+head->data;

}

int main(){
    vector<int>head = {1,2,4,-1,-1,5,-1,6,-1,7,-1,-1,3,-1,-1};

    Node* hea =generateTree(head);

    cout<<"Printitng inorder traversal"<<endl;

    inordertraversal(hea);

    cout<<endl<<"Printing the level order traversal"<<endl;

    printinglevelwise(hea);

    cout<<endl<<"Printig the height of the tree "<<endl<<returnheightofthetree(hea);

    cout<<endl<<"No of node in a tree "<<coutthenoofNode(hea)<<endl; 

    cout<<"Print the sum of the node"<< sumofNode(hea);


} 