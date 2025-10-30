#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void slidingWindowProtocal(vector<int>v, int k){
   priority_queue<pair<int, int>>pq;

   for(int i=0; i<k; i++){
    pq.push(make_pair(v[i], i));
   }

   cout<<pq.top().first<<" ";

   for(int i=k; i<v.size(); i++){
    while(!pq.empty() && pq.top().second<= (i-k) ){
        pq.pop();


    }

    

    pq.push(make_pair(v[i], i));

    cout<<pq.top().first<<" ";

   }

}
int main(){

    vector<int>v={1,2,3,4,5,6,7,8,9,10};

    slidingWindowProtocal(v, 3);



}