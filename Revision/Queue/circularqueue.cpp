#include<iostream>
using namespace std;

class queue{
    int * arr;

    int capacity;
    int size;

    int front;
    int rear;

    public:

    queue(int capacity){
       
        arr= new int[capacity];
        this->capacity=capacity;

        size=0;
        front=0;
        rear=-1;
    }

    void push(int data){

        if(size==capacity){
            cout<<"queue is full";
            return;
        }
        rear = (rear+1)%capacity;

        arr[rear] = data;

        size++;


    }

    void pop(){

        if(empty()){
            cout<<"can not pop the element in the queue queue is empty";
            return;

        }

        front = (front+1)%capacity;
        size--;

    }

    int front1(){

        if(empty()){
            cout<<"can not pop the element in the queue queue is empty";
            return -1;

        }

        return arr[front];



        

    }

    bool empty(){
        if(size==0){
            return true;
        }

        return false;

    }

    void rear1(){

        cout<<"rear is "<<arr[rear];
        
    }

};



int main(){
    queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    // q.push(5);

    cout<<q.front1()<<" ";
    q.pop();
    cout<<q.front1();
    q.push(1);
    cout<<q.front1();

    q.rear1();


}