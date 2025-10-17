#include<iostream>
#include<vector>
using namespace  std;
class stack{
    vector<int>v;

    public:
    void push_back(int data){
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

    int top(){
        if(v.empty()){
            return -1;
        }
        return v.back();
    }
};
int main(){
    stack s;

    s.push_back(1);
    s.push_back(2);
    s.push_back(3);

    while(s.top()!=-1){
        cout<<s.top()<<" ";

        s.pop_back();
    }

    cout<<s.top();
}