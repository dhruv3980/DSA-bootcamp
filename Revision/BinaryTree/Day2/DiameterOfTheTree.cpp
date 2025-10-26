#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node( int data){
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

    root->left=buildTree(arr, size);
    root->right=buildTree(arr, size);

    return root;

}

int heigth(Node* root){
    if(root==NULL) return 0;

    int leftheight = heigth(root->left);
    int rightheight = heigth(root->right);


    return max(leftheight,rightheight)+1;
}
int Diameter(Node* root){ // O(n^2)

    if(root==NULL) return 0;

    int currentDiameter = heigth(root->left)+heigth(root->right)+1;

    int leftDiameter = Diameter(root->left);
    int rightDiameter = Diameter(root->right);

    return max(currentDiameter, max(leftDiameter, rightDiameter));


}


pair<int,int>  diameter(Node* root){ // Diameter, height
    if(root==NULL) return make_pair(0,0);

    int currentDiameter = diameter(root->left).second+diameter(root->right).second+1;

    int finalheight = max(diameter(root->left).second , diameter(root->right).second)+1;
    
    int leftDiameter = diameter(root->left).first;
    int rightDiameter = diameter(root->right).first;


    return make_pair(max(currentDiameter, max(leftDiameter, rightDiameter)), finalheight);


}


bool isIdentical(Node*root, Node*subtree){
    if(root==NULL && subtree==NULL) return true;

    if(root==NULL || subtree==NULL) return false;

    return isIdentical(root->left, subtree->left) && isIdentical(root->right, subtree->right);


}

bool SubtreeOfAnotherTree(Node* root, Node* subtree){
     if(root==NULL && subtree==NULL) return true;
     if(root==NULL || subtree==NULL) return false;


    if(root->data ==subtree->data){
       bool ans= isIdentical(root, subtree);
       if(ans){
        return true;
       }

    }


    bool issubtree = SubtreeOfAnotherTree(root->left, subtree);
    if(!issubtree){

        return SubtreeOfAnotherTree(root->right, subtree);

    }

    return true;
}

int main(){

    int arr[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int size=13;

    Node* root =buildTree(arr, size);

    Node* subtree = new Node(2);
    subtree->left = new Node(4);

    subtree->right = new Node(5);

    cout<<SubtreeOfAnotherTree(root, subtree);




    //cout<<"Diameter of the tree "<<diameter(root).first<<endl;

    

    //cout<<"Diameter Of The Tree "<<Diameter(root);

}