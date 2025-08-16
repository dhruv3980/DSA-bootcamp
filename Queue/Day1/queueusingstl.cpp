#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int>s;
    s.push(5);
    s.push(10);
    cout<<"Printing the top most element "<<s.front();
}