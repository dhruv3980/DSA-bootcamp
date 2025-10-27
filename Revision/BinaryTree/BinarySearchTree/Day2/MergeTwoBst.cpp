#include<iostream>
#include<vector>
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


void calculateInorderSequence(Node* root, vector<int>& path){
    if(root==NULL) return;


    calculateInorderSequence(root->left, path);
    
    path.push_back(root->data);
    calculateInorderSequence(root->right, path);
}



Node* bstFromSortedArray(vector<int>&arr, int start, int end){

    int mid = start+(end-start)/2;

    if(start>end){
        return NULL;
    }

    Node* root = new Node(arr[mid]);
    root->left = bstFromSortedArray(arr, start, mid-1);
    root->right = bstFromSortedArray(arr, mid+1, end);

    return root;

}
Node* mergeTwoSortedBst(Node* root1, Node* root2){

    vector<int>first;
    vector<int>second;

    calculateInorderSequence(root1, first);

    calculateInorderSequence(root2, second);

    
   
    vector<int> third;

    int i=0; 
    int j=0;
    while(i<first.size() && j<second.size()){
        if(first[i]<second[j]){
            third.push_back(first[i]);
              i++;
        }else{
            third.push_back(second[j]);
             j++;
        }

      
       

    }

    while(i!=first.size()){
        third.push_back(first[i]);
        i++;
    }

    while(j!=second.size()){
        third.push_back(second[j]);
        j++;
    }


    

    return bstFromSortedArray(third, 0, third.size()-1);


}

void inorderPrint(Node* root){
    if(root==NULL) return ;

   
    inorderPrint(root->left);
     cout<<root->data<<" ";

    
    inorderPrint(root->right);
}
int main(){

    Node* root1 = new Node(2);

    root1->left=new Node(1);

    root1->right = new Node(4);



    Node* root2 = new Node(9);

    root2->left=new Node(3);

    root2->right = new Node(12);

    Node* root=mergeTwoSortedBst(root1, root2);

    inorderPrint(root);





}