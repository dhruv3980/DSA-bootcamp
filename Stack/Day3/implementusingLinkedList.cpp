#include<iostream>
#include<list>

using namespace std;

class stack{
    list<int>v;
    public:

    void push(int val){
        v.push_front(val);

    }
    void pop(){
        v.pop_front();

    }

    int top(){
       return v.front();

    }

    bool isEmpty(){
        return v.size()==0;

    }

    


};

int main(){

    stack st;
    st.push(1);
    st.push(2);
    st.push(3);

    while(!st.isEmpty()){
        cout<<st.top()<<" ";
        st.pop();

    }
 
}