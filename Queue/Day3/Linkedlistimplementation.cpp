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

class queue{
    Node* head;
    Node* tail;

    
    public:
        queue(){
            head = NULL;
            tail=NULL;
        }

 
        void push(int data ){
            if(head==NULL){
                Node* newNode = new Node(data);

                head = newNode;
                tail = newNode;
            }
            else{
                Node* newNode = new Node(data);

                tail->next = newNode;
                
                tail = newNode;

            }
        }

        void pop(){
            if(isEmpty()){
                cout<<"queue is empty";
            }

            Node* temp = head;

            head=head->next;
            
            delete temp;
            
        }
        
        int getfront(){
            if(head==NULL){
                return -1;
            }

            return head->data;
        }
        
        bool isEmpty(){
            return head==NULL;
        }

};
int main(){

    queue q;

    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.isEmpty()){
        cout<<q.getfront()<<" ";
        q.pop();
    }

    q.getfront();


}