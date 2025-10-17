#include<iostream>
#include<stack>
using namespace std;
void pushatBottom(stack<int>&s, int data){
    if(s.empty()){
        s.push(data);
        return;
    }
    int dat = s.top();

    s.pop();
    pushatBottom(s, data);

    s.push(dat);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3); 


    pushatBottom(s, 4);

    while(!s.empty()){
        cout<<s.top()<<" ";

        s.pop();
    }

}