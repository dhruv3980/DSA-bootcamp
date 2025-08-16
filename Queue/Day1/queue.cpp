#include<iostream>
using namespace std;

class queue{
    public:
    int size;
    int * arr;
    int front;
    int rear;

    queue(int size){
        this->size = size;
        arr = new int[size];
        this->front = 0;
        this->rear = 0;
    }

    void push (int element){
        // check queue is full or not 
        if(rear == size-1){
            cout<<"Queue is full cant insert";
            return;
        }

        else {
            // queue is not full
           
            arr[rear] = element;
             rear++;
        }

    }

    void pop (){
        // check queue is not empty
        if(front==rear){
            cout<<"queue is empty ";
        }
        else {
            front++;
        }
    }

    // get front 
    int getfront (){
        // check queue is empty or not
        if(rear == front){
            return -1;

        }
        else {
            return arr[front];
        }
    }

    // is empty 
    bool isempty (){
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    // get size ;

    int getsize (){
        return rear-front;

    };




    void print (){
        for(int i=0; i<size; i++){
            cout<<arr[i];
        }
    }

};

int main(){
    queue q(10);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    q.print();


}

