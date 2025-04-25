#include<iostream>
#include<stack>
using namespace std;
void insertelementinasortedstack(stack<int>&s, int& target){
    if(s.empty()){
        s.push(target);
        return;
    }

    int topelement = s.top();
    if(topelement>=target){
        s.push(target);
        return;
    }
    else{
   
        
        s.pop();
        insertelementinasortedstack(s,target);
    }
    

    s.push(topelement);




}
void sortstack(stack<int>& s){
    if(s.empty()){
        return;
    }
    int topelement = s.top();
    s.pop();
    sortstack(s);

    insertelementinasortedstack(s, topelement);

}
int main(){
    stack<int>s;
    s.push(3);
    s.push(1);
    s.push(5);
    s.push(7);
    s.push(11);
    sortstack(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}