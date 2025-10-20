#include<iostream>
#include<deque>
using namespace std;
class stack{
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

    bool empty(){

        return q.empty();

    }
};
int main(){`

    stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

}