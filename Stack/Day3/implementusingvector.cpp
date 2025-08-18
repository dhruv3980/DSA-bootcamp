#include<iostream>
#include<vector>
using namespace std;
class Stack{
    vector<int>v;
    
    public:
        void push(int val){
            v.push_back(val);
        }

        void pop(){
            v.pop_back();

        }

        int top(){
            return v[v.size()-1];
        }

        bool isEmpty(){
            return (v.size())==0;
            

        }
    

};
int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);

    while(!st.isEmpty()){
        cout<<st.top()<<" ";
        st.pop();

    }
    
    



}