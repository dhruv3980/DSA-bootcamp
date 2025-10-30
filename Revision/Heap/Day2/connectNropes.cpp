// connect n ropes in such a way that the cost will be minimum
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int cost (vector<int>roplenght){
    int ans=0;

    priority_queue<int, vector<int>, greater<int>>pq(roplenght.begin(), roplenght.end());

    
    while(pq.size()>1){
         int first = pq.top();
         pq.pop();

         int second = pq.top();
         pq.pop();

         int sum = first+second;

         ans+=sum;
         pq.push(sum);

    }


    return ans;


}
int main(){
    vector<int>ropLength = {4,3,2,6};

    cout<<"Min Cost is "<<cost(ropLength);
}