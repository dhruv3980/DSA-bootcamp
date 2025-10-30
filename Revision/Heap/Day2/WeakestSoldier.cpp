#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct  great
{
    /* data */

    bool operator()(const pair<int, int>& fir, const pair<int, int>&sec) const{
        if(fir.first==sec.first){
           return fir.second>sec.second;
                
           
        }

        return fir.first>sec.first;
    }
};


void WeakestSoldier(vector<vector<int>>arr, int k){
    vector<pair<int, int>>ans; // here two thing first one is the total soldier and the second one is the idx

    for(int i=0; i<arr.size(); i++){
        int count=0;
        for(int j=0; j<arr.size(); j++){
            if(arr[i][j]==1){
                count++;
            }

        }

        ans.push_back(make_pair(count, i));

    }


    priority_queue<pair<int, int>, vector<pair<int, int>>,  great>pq(ans.begin(), ans.end());

    for(int i=0; i<k; i++){
        
        cout<<"Row "<<pq.top().second<<endl;
        pq.pop();
    }
}
int main(){
    vector<vector<int>>arr = {{1,0,0,0},{1,1,1,1},{1,0,0,0}, {1,0,0,0}};

    int k=2;

    WeakestSoldier(arr, k);
}