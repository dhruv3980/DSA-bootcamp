#include<iostream>
#include<deque>
using namespace std;

class Stack{
    deque<int>q;
    public:
        void push(int data){
            q.push_back(data);

        }

        void pop(){
            q.pop_back();
        }

        int top(){
            return q.back();
        }

        bool isEmpty(){
            return q.empty();
        }

};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}