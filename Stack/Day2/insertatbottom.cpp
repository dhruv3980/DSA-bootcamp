#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int>&s, int& target){
    //Base Case
    if(s.empty()){
        s.push(target);
        return;
    }

    // find top element
    int topelement = s.top();
    s.pop();
    // Recursive call
    solve(s,target);

    s.push(topelement);

}
void insertatBottom(stack<int>&s){
    if(s.empty()){
        cout<<"stack is underflow "<<endl;
        return;
    }

    int target = s.top();
    s.pop();
    solve(s,target);
}
int main(){
    stack<int>s;
    for(int i=10; i<=50; i+=10){
        s.push(i);
    }

  
    

    

    insertatBottom(s);

    cout<<"printing the stack "<<endl;

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

}