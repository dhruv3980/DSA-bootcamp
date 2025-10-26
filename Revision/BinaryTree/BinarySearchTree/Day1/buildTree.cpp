#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=right=NULL;
    }
};


Node* bstHelper(Node* root, int data){
    if(root==NULL){
        return new Node(data);
    }

    if(root->data>data){
      root->left= bstHelper(root->left, data);
    }
    else{
       root->right= bstHelper(root->right, data);
    }

    return root;
}

Node* buildTree(int arr[], int size){
    Node* root = NULL;

    for(int i=0; i<size; i++){
        root=bstHelper(root, arr[i]);
    }


    return root;
}

void print(Node* root){
    if(root==NULL){
        return;
    }


    print(root->left);
    cout<<root->data<<" ";
    
    print(root->right);
}


bool searchInAKey(Node* root, int key){

    if(root==NULL) return false;

    if(root->data==key) return true;

    if(root->data>key)  return searchInAKey(root->left, key);

    else{
        return searchInAKey(root->right, key);
    }
}


Node* inOrderSuccessor(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }

    return root;
}

Node* DeleteInATree(Node* root, int data){
    if(root==NULL)  return NULL;

    if(root->data>data){
        root->left= DeleteInATree(root->left, data);
    }
    else if(root->data<data){
        root->right=DeleteInATree(root->right, data);
    }else{
        // 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;

        }
        if(root->left==NULL || root->right==NULL){


            return root->left==NULL? root->right:root->left;

        }

        // now here the case 3 two children 
        // for two children 
        // first find inorder successor then replace the value then delte 

        Node* in = inOrderSuccessor(root->right);

        root->data = in->data;

        root->right= DeleteInATree(root->right, in->data);

        return root;

    }

   

}



void PrintInARange(Node* root, int start, int end){
    if(root==NULL) return;

    if(root->data>=start && root->data<=end){

        PrintInARange(root->left, start, end);
        
      
        cout<<root->data<<" ";

     
        PrintInARange(root->right, start, end);
    }

    if(root->data<start){
        PrintInARange(root->right, start, end);
    }

    if(root->data>end){
        PrintInARange(root->left, start, end);
    }
}


void helper(Node* root, vector<int>& path){
    if(root==NULL)  return;


    path.push_back(root->data);
    if(root->left==NULL && root->right ==NULL){
        for(int i=0; i<path.size(); i++){
            cout<<path[i]<<" ";
        }

        cout<<endl;

        
    }

    

    helper(root->left, path);
    helper(root->right, path);

    path.pop_back();
}

void RootToLeafPath(Node* root){
    vector<int>v;

    helper(root, v);
}



bool validateBSt(Node* root, int min , int max){
    if(root==NULL)  return true;

    if(root->data<min && min!=-1){
        return false;
    }

    if(root->data>max && max!=-1){
        return false;
    }

   return validateBSt (root->right, root->data, max) && validateBSt(root->left, min, root->data);
}

int main(){
    int arr[]={8,5,3,1,4,6,10,11,14};
    int n =9; 


    Node* root=buildTree(arr, 9);

    print(root);
    cout<<endl;

    cout<<searchInAKey(root, 15)<<endl;


    DeleteInATree(root, 8);

    print(root);

    cout<<endl;

    PrintInARange(root, 5,11);

    RootToLeafPath(root);

    cout<<validateBSt(root, -1, -1);

}