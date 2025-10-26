#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data= data;
        left=right=NULL;
    }
};

static int idx=-1;
Node* buildTree(int arr[], int size){
    idx++;
    if(arr[idx]==-1){
        return NULL;
    }

    Node* root = new Node(arr[idx]);

    root->left = buildTree(arr, size);

    root->right = buildTree(arr, size);


    return root;


}


bool pathcalculate(Node* root, int n1, vector<int>& path){
    if(root==NULL) {
        return false;
    }

    path.push_back(root->data);

    if(root->data == n1) return true;

    if(pathcalculate(root->left, n1, path)||pathcalculate(root->right, n1, path)){
        return true;
    }

    path.pop_back();

    return false;

   
}

int LowestCommonAncestor(Node* root,  int n1, int n2 ){
    vector<int> path1;
    vector<int>path2;

    pathcalculate(root, n1, path1);

    pathcalculate(root, n2, path2);

    

    int lca=-1;
    for(int i=0, j=0; i<path1.size() && j<path2.size(); i++, j++){
        if(path1[i]!=path2[j]){
            return lca;

        }
        lca=path1[i];


    }


    return lca;
    

}


int lca(Node* root, int n1, int n2){
    if(root==NULL) return -1;

    if(root->data==n1 || root->data ==n2){
        return root->data;
    }

    int leftans = lca(root->left, n1, n2);
    int rightans = lca(root->right, n1, n2);

    if(leftans!=-1 && rightans!=-1){
        return root->data;
    }

    return leftans==-1? rightans:leftans;
}

int main(){
    int arr[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int size = 13;

    Node* root = buildTree(arr, size);

    cout<<lca(root, 3,6);
}