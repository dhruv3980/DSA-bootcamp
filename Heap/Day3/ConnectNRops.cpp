#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void connectnrops(vector<int>p){
    priority_queue<int, vector<int>, greater<int>>q(p.begin(), p.end());
    int ans=0;

    while(q.size()>1){
        int first = q.top();
        q.pop();
        int second=q.top();
        q.pop();

        ans+=first+second;

        q.push(first+second);

    }

    cout<<"cost of connected n rows "<<ans;


}
int main(){
    vector<int>p {4,3,2,6};

    connectnrops(p);
}