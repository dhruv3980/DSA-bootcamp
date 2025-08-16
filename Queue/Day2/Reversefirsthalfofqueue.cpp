#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void reverse(queue<int>&q,int&k){
    // base case 
    stack<int>s;
    if(k<=0 || k>q.size()){
        return;

    }

    // now fill up the k element in the stack
    int count = 0;
    while(count<k){
        // queue front element pop
        // fill the stack
        int topelement = q.front();
        q.pop();
        count++;

        s.push(topelement);
    }

    // now again fill in the queue

    while(!s.empty()){
        int topelement = s.top();
        s.pop();
        q.push(topelement);

    }

    int sum = q.size()-k;

    while(sum>0){
      int topelement = q.front();
      q.pop();

      q.push(topelement);

      sum--;


    }

}
int main(){
    queue<int>q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(12);
    q.push(15);
    int k =3;

    reverse(q, k);

    // print to check whether the queue is reverse or not
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
   

}