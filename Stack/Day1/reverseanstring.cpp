#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<char>s;
    string a = "Dhruv Sahu";

    for(int i=0; i<a.size(); i++){
        s.push(a[i]);
    }
    string p;
    while(!s.empty()){
        p+=s.top();
        s.pop();


    }
    cout<<p;

}