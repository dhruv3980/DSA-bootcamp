#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>s;
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);
    s.push(0);

    cout<<"Printing the top of the stack "<< s.top()<<endl;

    cout<<"Check stack is empty or not " ;
    if(s.empty()){
        cout<<true<<endl;
    }
    else{
        cout<<false<<endl;
    }


    cout<<"Printing the size of the stack "<<s.size()<<endl;

    cout<<"Remove the element in  the stack "<<endl;
    

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
        
    }




}