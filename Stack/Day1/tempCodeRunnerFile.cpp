#include<iostream>
#include<stack>
using namespace std;

void printmiddleelement(stack<int>&s, int& totalsize){
    if(s.size()==0){
        cout<<"there is no element in the stack so i am not return any middle bye";
        return;
}}

int main (){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    s.push(90);
    s.push(100);
    int size = 10;

    printmiddleelement(s, size);
}