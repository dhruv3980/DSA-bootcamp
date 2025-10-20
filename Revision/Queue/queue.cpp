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


class Queue{
    Node* front;
    Node* rear;



    public:
    Queue(){
        front=rear=NULL;
    }

    void push(int data){
        Node * newNode = new Node(data);
        if(empty()){

            rear=front =newNode;

        }
        else{
            rear->next = newNode;
            rear = newNode;
        }

    }

    void pop(){

        if(empty()){
            cout<<"queue is empty";
            return;
        }
        Node* temp = front;

        front = front->next;

        temp->next = NULL;

        delete temp;

    }

    int front1(){

        if(empty()){
            cout<<"queue is empty";
            return -1;
        }

        return front->data;

    }

    bool empty(){

        return front==NULL;

    }
    

};
int main(){

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout<<q.front1()<<" ";
        q.pop();
    }

    q.pop();
    

}