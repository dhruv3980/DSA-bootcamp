#include<iostream>
#include<queue>
using namespace std;
void interleave(queue<int>&q){
    // helper queue
    queue<int>p;
    int n = q.size();
    

    for(int i=0; i<n/2; i++){
        p.push(q.front());
        q.pop();
    }

    // now  interleave // here if you loop n times then p is empty
    for(int i=0; i<n/2; i++){
        q.push(p.front());
        p.pop();

        q.push(q.front());
        q.pop();
    }


};
int main(){
    queue<int>q;
    int n =10;
    // push the element in the queue
    for(int i=0; i<n; i++){
        q.push(i);
    }
    interleave(q);

    for(int i=0; i<n; i++){
        cout<<q.front()<<" ";
        q.pop();

    }


}