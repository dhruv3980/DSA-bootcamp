#include<iostream>
#include<stack>
using namespace std;

void insertatrightplace(stack<int>&s, int topelement){
    if(s.empty() || s.top()>topelement){
        s.push(topelement);
        return;
    }
   
    int temp = s.top();
    s.pop();
    insertatrightplace(s, topelement);

    s.push(temp);

}

void sort(stack<int>&s){
    if(s.empty()){
        return;
    }

    int topelement = s.top();
    s.pop();

    sort(s);

    insertatrightplace(s, topelement);

}
int main(){
    stack<int>s;
    s.push(3);
    s.push(2);
    s.push(5);
    s.push(1);

    sort(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
        
    }
}