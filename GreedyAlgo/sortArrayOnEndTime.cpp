#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int>p1, pair<int, int>p2){
    return p1.second<p2.second;
}

int main(){
    vector<int>p1 = {1,3,5,7,4,9,8};
    vector<int>p2 = {7,1,2,6,7,4,6};

    vector<pair<int, int>> q;

    for(int i=0; i<p1.size(); i++){
        q.push_back(make_pair(p1[i], p2[i]));
    }

    cout<<" printing pait"<<endl;
    for(int i=0; i<q.size(); i++){
        cout<<q[i].first<<"-"<<q[i].second<<endl;
    }

    // now sort q
    sort(q.begin(), q.end(), compare);

    cout<<" sorted pair"<<endl;
    for(int i=0; i<q.size(); i++){
        cout<<q[i].first<<"-"<<q[i].second<<endl;
    }
}
