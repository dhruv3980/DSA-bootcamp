#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data= data;
        next = NULL;

    }
};

class LinkedList{
    public:
    Node* head;
    Node* tail;

    LinkedList(){
        head=tail=NULL;
    }

    void push_back(int data){
        Node* newNode= new Node(data);

        if(head==NULL){
            head =tail = newNode;
        }
        else{
            tail->next = newNode;
            tail=newNode;
        }
    }

    void print(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }

        cout<<"NULL"<<endl;
    }

};

Node* split(Node* head){
    Node* prev=NULL;
    Node* slow=head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        prev=slow;
        slow=slow->next;
        fast = fast->next->next;
    }

    if(prev==NULL){
        return NULL;
    }

    prev->next=NULL;

    return slow;
}


Node* merge(Node* left, Node* right){

    if(left==NULL && right==NULL){
        return NULL;
    }

    LinkedList ans;

    Node* prev=NULL;

    while(left!=NULL && right!=NULL ){
        if(left->data<right->data){
            ans.push_back(left->data);
            
            left=left->next;

        }else{
            ans.push_back(right->data);
            
            right= right->next;
        }


    }

     // Add remaining nodes from left list
    while (left != NULL) {
        ans.push_back(left->data);
        left = left->next;
    }

    while(right!=NULL){
        ans.push_back(right->data);
        right=right->next;
    }

    return ans.head;


    // if (left == NULL) return right;
    // if (right == NULL) return left;

    // Node* result = NULL;

    // if (left->data < right->data) {
    //     result = left;
    //     result->next = merge(left->next, right);
    // } else {
    //     result = right;
    //     result->next = merge(left, right->next);
    // }

    // return result;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head= head->next;
    }
    cout<<"NULL"<<endl;
}

Node* mergeSort(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* righthead = split(head);

  

    Node* left = mergeSort(head);
    Node* right =mergeSort(righthead);

    return merge(left, right);
    
}


int main(){
    LinkedList ll;
    ll.push_back(5);
    ll.push_back(4);
    ll.push_back(3);
    ll.push_back(2);
   
     ll.print();

    Node* head = mergeSort(ll.head);

   

    print(head);




}