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
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

int idx=-1;
Node* createTree(vector<int> a){
    idx++;
    if(a[idx]==-1) return NULL;

    Node* currentNode= new Node(a[idx]);
    currentNode->left = createTree(a);
    currentNode->right = createTree(a);

    return currentNode;

}

int  calculateheightfromtheroot(Node*head, int currentNode, vector<int>&p1){

    if(head==NULL) return -1;


    int currentNod = head->data;

    p1.push_back(currentNod);

    if(currentNode==currentNod){
        
        return 1;
    }

    int leftans =calculateheightfromtheroot(head->left, currentNode, p1);

    if(leftans!=-1){
        return p1.size();
    }
    int rightans = calculateheightfromtheroot(head->right, currentNode, p1);

    if(rightans!=-1){
        return p1.size();

    }
    p1.pop_back();

    return -1;


}


void printTheLowestCommonAncestor(Node* head, int firstNode , int secondNode){
    vector<int>p1;
    vector<int>p2;

    int leftans =calculateheightfromtheroot(head, firstNode, p1);
    int rightans=calculateheightfromtheroot(head, secondNode, p2);

    

   int lca =-1;

   int n = min(p1.size(), p2.size());

    for (int i = 0; i < n; i++) {
        if (p1[i] == p2[i])
            lca = p1[i];  // update LCA while nodes match
        else
            break;           // first mismatch, stop
    }

    if(lca==-1){
        cout<<"doest exist lca";
    }
    else{
        cout<<lca;
    }




}

void printthetree(Node* head){
    if(head==NULL) return;
    queue<Node*>q;
    
    q.push(head);
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

Node* LCA2(Node* head, int n1, int n2){
    if(head==NULL) return NULL;


    if(head->data==n1 || head->data==n2){
        return head;
    }
   

    Node* leftlca = LCA2(head->left,  n1, n2 );
    Node* rightlca = LCA2(head->right, n1, n2);

    if(leftlca!=NULL && rightlca!=NULL){
       
        return head;
    }

    return leftlca==NULL? rightlca:leftlca;
}
int main(){
    vector<int> a ={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* head = createTree(a);

    printthetree(head);
    cout<<endl;

    printTheLowestCommonAncestor(head,2,4);

    Node* ans = LCA2(head, 2,7);

    cout<<endl<<"Print the answer "<< ans->data;

}