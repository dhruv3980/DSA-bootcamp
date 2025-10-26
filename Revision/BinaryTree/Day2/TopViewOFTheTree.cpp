#include<iostream>
#include<queue>
#include<map>
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

static int idx = -1;
Node* buildTree(int arr[], int size){
    idx++;
    if(arr[idx]==-1){
        return NULL;
    }

    Node* root = new Node(arr[idx]);

    root->left = buildTree(arr, idx);

    root->right = buildTree(arr, idx);

    return root;
    
}


void TopViewOfTree(Node* root){

    queue<pair<Node*, int>>q; // data hd

    q.push(make_pair(root, 0));

    map<int, int>m;

    while(!q.empty()){
       pair<Node*, int> currentNode = q.front();
        q.pop();

        int currentHD= currentNode.second;
        
        if(m.count(currentHD)==0){
            m[currentHD]=currentNode.first->data;
        }
        

        if(currentNode.first->left!=NULL){
            q.push(make_pair(currentNode.first->left, currentHD-1));
        }

         if(currentNode.first->right!=NULL){
            q.push(make_pair(currentNode.first->right, currentHD+1));
        }
    }



    for(auto it: m){
        cout<<it.second<<" ";
    }
    cout<<endl;


}




void BottomViewOfTree(Node* root){

    queue<pair<Node*, int>>q; // data hd

    q.push(make_pair(root, 0));

    map<int, int>m;

    while(!q.empty()){
       pair<Node*, int> currentNode = q.front();
        q.pop();

        int currentHD= currentNode.second;
        
        
            m[currentHD]=currentNode.first->data;
        
        

        if(currentNode.first->left!=NULL){
            q.push(make_pair(currentNode.first->left, currentHD-1));
        }

         if(currentNode.first->right!=NULL){
            q.push(make_pair(currentNode.first->right, currentHD+1));
        }
    }



    for(auto it: m){
        cout<<it.second<<" ";
    }
    cout<<endl;


}
int main(){

    int arr[]={1,2,-1,4,-1,5,-1,6,-1,-1,3,-1,-1};

    int size = 13;

    Node* root = buildTree(arr, size);

    TopViewOfTree(root);

    BottomViewOfTree(root);



















}