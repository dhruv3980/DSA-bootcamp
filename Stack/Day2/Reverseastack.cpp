#include<iostream>
#include<stack>

using namespace std;

void solve(stack<int>&s, int& topelement){
    if(s.empty()){
        s.push(topelement);
        return;
    }

    int target = s.top();
    s.pop();
    solve(s,topelement);

    s.push(target);




}


void reverse(stack<int>&s){
    // Base case
    if(s.empty()){
        
        return;
    }

    int topelement = s.top();
    s.pop();
    reverse(s);
    
    solve(s,topelement);

}

int main(){
    stack<int>s;
    for(int i=10; i<=50; i+=10){
        s.push(i);
    }

    reverse(s);


   
    cout<<"printing the stack "<<endl;

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

}