#include<iostream>
#include<deque>
using namespace std;
class queue{
    deque<int>q;

    public:
        void push(int d){
            q.push_back(d);

        }

        void pop(){
            q.pop_front();
        }

        int front(){
            return q.front();
        }

        bool empty(){
            return q.empty();
        }

        
};
int main(){
    queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    
}