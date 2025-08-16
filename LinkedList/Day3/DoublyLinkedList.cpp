#include<iostream>
using namespace std;
class Node{
    public: 
        int data;
        Node* next;
        Node* prev;

        Node(int data){
            this->data = data;
            next = NULL;
            prev = NULL;
        }
};

class doublyLL {
    public:
        Node*head;
        Node*tail;

        doublyLL(){
            head=tail=NULL;
        }

        void push_front(int data){
            if(head==NULL){
                Node* newNode = new Node(data);

                head = newNode;
                tail=newNode;
            }
            else{
                Node* newNode = new Node(data);
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }

        void push_back(int data){
            if(head==NULL){
                Node* newNode = new Node(data);
                head = newNode;
                tail= newNode;
            }
            else{
                Node* newNode = new Node(data);
                newNode->prev = tail;
                tail->next = newNode;
                tail = newNode;
            }
        }


        void pop_front(){
            if(head == NULL) {
                cout<<"LinkedList empty we cant delete anything";
                return;
            }
            Node* temp = head;
            head = head->next;
            if(head!=NULL){
                head->prev = NULL;
            }
            temp->next = NULL;
            delete temp;

        }

        void pop_back(){
            if(tail == NULL){
                cout<<"Nothing to delete";
                return;

            }

            Node* temp = tail;
            if(head==tail){

                head=NULL;
                tail==NULL;
                delete temp;
                return;

            }
            tail=tail->prev;

            if(tail!=NULL){
                tail->next = NULL;
            }

            temp->prev = NULL;
            delete temp;
        }


        void print (){
            Node *temp = head;

            while(temp!=NULL){
                cout<<temp->data<< "<->";
                temp=temp->next;
            }

            cout<<"NULL\n";
        }


};
int main(){

    doublyLL dll;
    dll.push_front(3);
    dll.push_front(4);
    dll.push_front(5);
    dll.push_front(6);

    dll.pop_back();
    dll.pop_back();
    dll.pop_back();
    dll.pop_back();
    dll.pop_back();

    // dll.pop_front();
    // dll.pop_front();
    // dll.pop_front();
    // dll.pop_front();
    // dll.pop_front();

    // dll.push_back(3);
    // dll.push_back(4);
    // dll.push_back(5);
    // dll.push_back(6);

    dll.print();

}