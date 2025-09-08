#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// build class for the tree node
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


// here generate tree with the help of the vector

int idx=-1;

Node* generatetree(vector<int>tree){
    if(tree.size()==0) return NULL;

    idx++;

    if(tree[idx]==-1) return NULL;

    Node* currentNode = new Node(tree[idx]);

    currentNode->left = generatetree(tree);

    currentNode->right = generatetree(tree);

    return currentNode;
}


void printthetree(Node* head){
    if(head==NULL) return;

    queue<Node*>q;
    q.push(head);
    q.push(NULL);

    while(!q.empty()){
        // in first 
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

int calculateheight(Node* head){
    if(head==NULL) return 0;

    int left = calculateheight(head->left);
    int right = calculateheight(head->right);

    return max(left, right)+1;
}

int diameterofthetree(Node*head){
    // 
    if(head==NULL) return 0;

    int includehead = calculateheight(head->left)+calculateheight(head->right)+1;

    int leftdiameter = diameterofthetree(head->left);
    int rightdiameter = diameterofthetree(head->right);

    return max(includehead, max(leftdiameter, rightdiameter));


}

pair<int, int> DiameterOFTheTree(Node*head){
    //
    if(head==NULL) return make_pair(0,0);

    pair<int, int> leftcall = DiameterOFTheTree(head->left) ;// this will return ld, lh
    pair<int, int> rightcall = DiameterOFTheTree(head->right); // this will return rd, rh

    int currentdiameter = leftcall.second+ rightcall.second +1;

    int maxdiameterbetweenleftandright = max(leftcall.first, rightcall.first);

    int finalheight = max(leftcall.second, rightcall.second)+1;

    return make_pair(max(currentdiameter, maxdiameterbetweenleftandright), finalheight);



}

int main(){
    vector<int> tree = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};

    Node* head = generatetree(tree);

    cout<<"Printitng the tree "<<endl;

    printthetree(head);

    cout<<"Print the diameter of the tree ";
    

    cout<<diameterofthetree(head)<<endl;

    cout<<"Print the diameter in the o[n] time  "<<DiameterOFTheTree(head).first<<" "<<DiameterOFTheTree(head).second<<" ";
}