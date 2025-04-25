#include<iostream>
#include<stack>
using namespace std;

void printmiddleelement(stack<int>&s, int& totalsize){
    if(s.size()==0){
        cout<<"there is no element in the stack so i am not return any middle bye";
        return;
    }

    // base case
    if(s.size()==(totalsize/2+1)){
        cout<<"Middle element is "<<s.top()<<endl;
        return;
    }

    int temp = s.top();
    s.pop();

    printmiddleelement(s,totalsize);

    // Backtrack

    s.push(temp);



}
int main(){
    stack<int>s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    int totalelement = s.size();

    printmiddleelement(s, totalelement);

    cout<<"Printing the stack element "<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    
}