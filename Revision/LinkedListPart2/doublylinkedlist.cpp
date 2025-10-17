#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        prev=next =NULL;
    }
};

class DoublyLL{
    public:
    Node* head;
    Node* tail;

    DoublyLL(){
        head=tail=NULL;
    }

    void pushfront(int data){
        Node* createNewNode = new Node(data);
        if(head==NULL){
            head=tail = createNewNode;

        }else{
            createNewNode->next = head;
            head->prev=createNewNode;
            head = createNewNode;
        }
    }

    void popfront(){
        Node* temp = head;

        
        if(head->next==NULL){
            delete  head;
            

        }else{
            head = head->next;
            temp->next=NULL;

            delete temp;

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
int main(){

    DoublyLL ll;

    ll.pushfront(5);
    ll.pushfront(4);
    ll.pushfront(3);
    ll.pushfront(2);
    ll.pushfront(1);

    ll.popfront();

    ll.print();
    
}