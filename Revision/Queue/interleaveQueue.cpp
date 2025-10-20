#include<iostream>
#include<queue>
using namespace std;

void interleavequque(queue<int>& original){
    int n = original.size();

    queue<int>first;

    for(int i=0; i<n/2; i++){
        int element = original.front();
        first.push(element);
        original.pop();

    
    }

   


    // now interleave

    while(!first.empty()){
        int element = first.front();
        
        original.push(element);
        first.pop();

        int ele = original.front();
      
        original.push(ele);
          original.pop();
    }

}
int main(){

    queue<int>q;
    for(int i=1; i<=10; i++){
        q.push(i);
    }

    interleavequque(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }


}