#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct compare
{
    bool operator()(const pair<int, int>&p1, pair<int, int>&p2){
        return p1.second<p2.second;
    }
};



void printwindowmaximum(vector<int>arr, int k){
    priority_queue<pair<int, int>, vector<pair<int,int>>, compare>p;

    for(int i=0; i<k; i++){
        p.push({i, arr[i]});
    }

    cout<<"index is "<<p.top().first<<" and the maximum is "<<p.top().second<<'\n';

    for(int i=k; i<arr.size(); i++){
        while(!p.empty() && p.top().first<=(i-k)){
            p.pop();
        }

        p.push({i, arr[i]});

        cout<<"index is "<<p.top().first<<" and the maximum is "<<p.top().second<<'\n';
    }
}

int main(){
    vector<int>arr = {1,3,-1,-3,5,3,6,7};

    int k=3;

    printwindowmaximum(arr, k);

}