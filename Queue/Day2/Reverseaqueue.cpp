#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void reverseusingstack(queue<int>& q){
    stack<int>s;
    while(!q.empty()){
       int element =  q.front();
       q.pop();
       s.push(element);
    }

    while(!s.empty()){
        int element = s.top();
        s.pop();
        q.push(element);

    }

    return;
}

void reverseusingrecursion (queue<int>&q){
    // 
    if(q.empty()){
        return;
    }
    // get top element then reverse call 
    int topelement = q.front();
    q.pop();
    reverseusingrecursion(q);
    
    q.push(topelement);
}
int main(){
    queue<int>q;
    q.push(3);
    q.push(5);
    q.push(7);
    q.push(9);

    //  reverseusingstack(q);
    // reverseusingrecursion(q);

    while(!q.empty()){
        cout<<q.front()<< " ";
        q.pop();
    }
    cout<<endl;


}