#include<iostream>
using namespace std;
/* class Node{
    int data;
    Node* next;

    public:
        Node(int data){
            this->data=data;
            this->next=NULL;
        }

}; */

class circularqueue{
    int rear;
    int front;
    int* arr;

    int capacity;
    int actualsize;

    public:
        circularqueue(int capacity){

            arr = new int[capacity];
            front=0;
            rear=-1;
            this->capacity= capacity;
            this->actualsize=0;

        }

        void push(int data){
            if(actualsize==capacity){
                cout<<"quque is full \n";
                return;
            }

            // now push the elemetn
            // first we move rear then push element
            rear = (rear+1)%capacity;
            arr[rear]= data;
            actualsize++;


        }

        void pop(){
            if(isEmpty()){
                cout<<"Nothing to removed queue is empty";
                return;
            }

            front = (front+1)%capacity;
            actualsize--;

        }

        int fronttop(){
            if(isEmpty()){
                cout<<"queue is empty";
                return -1;
            }

            return arr[front];
        }
        bool isEmpty(){
            if(actualsize==0){
                return true;
            }
            else{
                return false;
            }
        }

        int  printrear(){
            if(isEmpty()){
                return -1;
            }
            return arr[rear];
        }

};
int main(){

    circularqueue  q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<q.fronttop()<<endl;
    q.pop();
    cout<<q.fronttop()<<endl;
    q.push(5);
    cout<<q.fronttop()<<endl;

    cout<<q.printrear()<<endl;

    


}