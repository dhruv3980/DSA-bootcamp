#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int>q;
    q.push_front(1);
    q.push_front(2); // 2 1

    q.push_back(3);
    q.push_back(4);  // 2  1  3  4

    cout<<q.front()<<" ";
    cout<<q.back();

}