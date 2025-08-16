#include<iostream>
#include<stack>
using namespace std;

void inseratbottom(stack<int>&s, int& topelement){
    if(s.empty()){
        s.push(topelement);
        return;
    }

    int topelement1 = s.top();
    s.pop();
    inseratbottom(s, topelement);

    s.push(topelement1);


}

void reverse(stack<int>&s){
    if(s.empty()){
        return ;
    }

    int topelement = s.top();
    s.pop();

    reverse(s);

    inseratbottom(s, topelement);

}
int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    reverse(s);

    cout<<"Printing the stack "<<endl;

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}