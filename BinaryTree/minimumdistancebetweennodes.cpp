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
            this->left=NULL;
            this->right=NULL;
        }
};

int idx=-1;
Node* createTree(vector<int>&arr){
    idx++;
    if(arr[idx]==-1){
        return NULL;
    }

    Node* head = new Node(arr[idx]);
    head->left = createTree(arr);
    head->right = createTree(arr);

    return head;

};


Node* LCA(Node* head, int n1, int n2){
    if(head==NULL) return NULL;

    if(head->data ==n1 || head->data==n2){
        return head;
    };

    Node* leftans = LCA(head->left, n1, n2);
    Node* rightans = LCA(head->right, n1, n2);

    if(leftans!=NULL && rightans!=NULL){
        return head;
    }

    return leftans==NULL? rightans:leftans;


    



}

int minimumdistance(Node* lowestcommonancestor, int data){
    if(lowestcommonancestor==NULL) return -1;

    if(lowestcommonancestor->data==data){
        return 0;
    }

    int leftans = minimumdistance(lowestcommonancestor->left, data);

    if(leftans!=-1){
        return leftans+1;
    }

    int rightans = minimumdistance(lowestcommonancestor->right, data);

    if(rightans!=-1){
        return rightans+1;
    }

    return -1;



}
int main(){
    vector<int> arr = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* head = createTree(arr);

    Node* Lowestcommonancestor = LCA(head, 5,3);
    


    int leftdistance = minimumdistance( Lowestcommonancestor, 5);

    

    int rightdistance=minimumdistance(Lowestcommonancestor,3);

    cout<<leftdistance+rightdistance;
}