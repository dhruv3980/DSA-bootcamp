#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* Next;

        Node(int data){
            this->data = data;
            Next = NULL;
        }
};

class CircularLL{
    public:
        Node* head;
        Node* tail;

        CircularLL(){
            head =tail = NULL;
        }

        void pushfront(int data){
            if(head ==NULL){
                Node*  newNode = new Node(data);
                head = newNode;
                tail = newNode;
                tail->Next= newNode;

            }
            else{
                Node* newNode = new Node(data);
                newNode->Next = head;
                tail->Next = newNode;
                head = newNode;

            }
        }

        void push_back(int data){
            if(head==NULL){
                Node* newNode = new Node(data);

                head = newNode;
                tail = newNode;
                tail->Next = newNode;
            }
            else{
                Node* newNode = new Node(data);

              
                tail->Next = newNode;
                
                newNode->Next =head; 
                tail = newNode;
            }
        }

        void popfront(){
            if(head ==NULL) return;

            if(head==tail){
                delete head;
                head=tail=NULL;
            }

            Node* temp = head;
            tail->Next = temp->Next;
            head = temp->Next;

            temp->Next = NULL;
            delete temp;
        }

        void popback(){
            if(head ==NULL) return;
            if(head==tail){
                delete head;
                
                head=tail =NULL;
                return;
            }

            
            Node* temp = head;
            while(temp->Next!=tail){
                    temp = temp->Next;
            }

            temp->Next = head;
            Node* deleteNode = tail;
            tail = temp;
            
            deleteNode->Next = NULL;
            delete deleteNode;
            return;

        }

        void print(){
            if(head==NULL){
                cout<<"empty";
                return;
            };

            cout<<head->data <<"->";
            
            Node* temp = head->Next;
            while(temp!=head){
                cout<<temp->data<<"->";
                temp=temp->Next;
            }
            cout<<head->data ;
        }

};
int main(){

    CircularLL m;
    m.pushfront(1);
    m.pushfront(2);
    m.pushfront(3);
    m.pushfront(4);
    m.pushfront(5);

    // m.popback();
    // m.popback();
    // m.popback();
    // m.popback();
    // m.popback();
    // m.popback();

    m.popback();
    m.popback();
    m.popback();
    m.popback();
    m.popback();

    m.print();

}