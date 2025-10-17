#include<iostream>
#include<vector>
using namespace  std;
template<class T>
class stack{
    vector<T>v;

    public:
    void push_back(T data){
        v.push_back(data);
    }

    void pop_back(){
        if(isEmpty()){
            cout<<"Stack is emplty"<<endl;
            return;
        }

        v.pop_back();
    }

    bool isEmpty(){
        if(v.size()<=0){
            return true;
        }
        else{
            return false;
        }
    }

    T top(){
        if(v.empty()){
            return T();
        }
        return v.back();
    }
};
int main(){
    stack<int> s;

    s.push_back(1);
    s.push_back(2);
    s.push_back(3);

    while(!s.isEmpty()){
        cout<<s.top()<<" ";

        s.pop_back();
    }

   
}