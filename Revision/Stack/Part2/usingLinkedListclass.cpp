#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
    T data;
    Node* next;

    Node(T data){
        this->data = data;
        next=NULL;
    }
};
template<class T>
class Stack{
    
    public:
    Node<T>* head;

    Stack(){
        head=NULL;
    }

    void push(T data){
        Node <T>* newNode = new Node<T>(data);
        if(head==NULL){
            head = newNode;

        }
        else{
            newNode->next = head;
            head=newNode;
        }
    }


    void pop(){
        Node <T>* temp = head;

        head = head->next;
        temp->next = NULL;

        delete temp;
    }

    T top(){
        return head->data;
    }

    bool empty(){
        return head==NULL;
    }

};
int main(){

    Stack<int>s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }


}