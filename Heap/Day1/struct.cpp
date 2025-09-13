#include<iostream>
#include<queue>
using namespace std;
struct compare{

    bool operator()  (const pair<string, int>&p1, pair<string, int>&p2) const{
        return p1.second<p2.second;
    }

};
int main(){

    priority_queue <pair<string,int>, vector<pair<string,int>>, compare> p;

    p.push(make_pair("siya", 49));
     p.push(make_pair("daya", 59));
     p.push(make_pair("gita", 9));
     p.push(make_pair("diya", 89));

     while(!p.empty()){
        cout<<p.top().first<<"-"<<p.top().second;
        p.pop();
     }
    
}