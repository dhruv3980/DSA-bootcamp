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
    Node* prev =NULL;
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;

    }

    if(prev!=NULL){
        prev->next=NULL;
    }

    return slow;

}

Node* merge(Node* left, Node* right){
    Node* head= left;
  

    while(left!=NULL && right!=NULL){
          Node* nextleft = left->next;
          Node* nextright = right->next;
        left->next= right;
        right->next = nextleft;
        left= nextleft;
        right = nextright;
    }

    if(right!=NULL){
        left->next=right;
    }

    return head;

}
Node* zigzag(Node* head){
    if(head ==NULL|| head->next==NULL) return head;

    Node* righthead = split(head);

    return merge(head, righthead);




}

 void print(Node* head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }

        cout<<"NULL"<<endl;
}
int main(){
    LinkedList ll;

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.push_back(5);

    ll.print();

    Node* temp= zigzag(ll.head);

    print(temp);

}