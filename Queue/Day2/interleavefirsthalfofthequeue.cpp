#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void interleave(queue<int>&q){
    int half = q.size()/2;
    int n = q.size();

    queue<int>p;


    while(half){
        int element = q.front();
        q.pop();
        p.push(element);
        half--;
    }

  

    // now interleave 
    while(!q.empty() && !p.empty()){
        // first pick up the element in the p and push into queue;
        int element = p.front();
        p.pop();

        q.push(element);

        // now pick up the element in the q and push into queue
        int element1 = q.front();
        q.pop();
        q.push(element1);

    }

    if((n)&1){ // odd case in odd case there will be one element present in the queue which is in the front it move 
        int element = q.front();
        q.pop();
        q.push(element);

    }





}
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);

    interleave(q);

    while(!q.empty()){
        // print q fornt element
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;


}
 