#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList{
     public:
    Node* head;
    Node* tail;
   

    LinkedList(){
        head=tail=NULL;
    }

    void push_front(int data){
        Node* newNode = new Node(data);

        if(head==NULL){
            head=newNode;
            tail = newNode;


        }
        else{
            newNode->next = head;
            head = newNode;
        }

    }


    void print(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<"\n";
    }
};

void checkcycle (Node* head){
    Node* slow =head;
    Node* fast =head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast= fast->next->next;

        if(slow==fast){
            cout<<"cycle found";
            return;
        }


    }

    cout<<"Cycle does't exist";
}

void removeCycle(Node* head){
    Node* fast = head;
    Node* slow = head;

    bool iscycleexist=false;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cout<<"Cycle exist"<<endl;
            iscycleexist=true;
            break;

        }

    }

    if(!iscycleexist){
        cout<<"cycle does not exist";

    }
    else{
        slow = head;

        if(slow==head){
            

            while(fast->next!=slow){
                fast = fast->next;
            }
            fast->next = NULL;

        }else{
             Node* prev=fast;

             while(fast->next!=NULL){
                slow = slow->next;
                prev=fast;
                fast=fast->next;
             }

             prev->next=NULL;
        }
    }


}
int main(){

    LinkedList ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.tail->next = ll.head;

    removeCycle(ll.head);
    
   ll.print();



}