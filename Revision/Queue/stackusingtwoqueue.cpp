#include<iostream>
#include<queue>

using namespace std;

class stack{
    queue<int> q1;
    queue<int> q2;

    public:

    void push(int data){
        while(!q1.empty()){
            int top = q1.front();

            q2.push(top);

            q1.pop();
        }

        q1.push(data);

        while(!q2.empty()){
            int top = q2.front();

            q1.push(top);

            q2.pop();
        }

    }
    void pop(){
        if(isEmpty()){
            cout<<"queue is empty";
            return;
        }

        q1.pop();


    }
    int top(){
        if(isEmpty()){
            return -1;
            
        }
        return q1.front();

    }

    bool isEmpty(){

        return q1.empty();

    }
};
int main(){

   stack q;
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.isEmpty()){
        cout<<q.top();
        q.pop();

    }

}