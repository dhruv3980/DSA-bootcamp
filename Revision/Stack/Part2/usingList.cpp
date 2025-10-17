#include<iostream>
#include<vector>
#include<list>
using namespace std;
template<class T>
class stack{
    list<T>l;

    public:

    void push(T val){
        l.push_front(val);

    }

    void pop(){
        l.pop_front();
    }

    T top(){
        return l.front();
    }

    bool Empty(){
        return l.empty();
    }

};
int main(){
    stack<int>s;
    s.push(3);
    s.push(2);
    s.push(1);

    while(!s.Empty()){
        cout<<s.top()<<" ";

        s.pop();
    }

}