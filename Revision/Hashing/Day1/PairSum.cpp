#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

pair<int, int> PairSum(vector<int>&v, int target){

    unordered_map<int, int>m; // first one is key

    for(int i=0; i<v.size(); i++){
        int final = target-v[i];

        if(m.find(final)!=m.end()){
            return {m[final], i};
        }

        m[v[i]] =i; 
    }
    
}
int main(){

    vector<int>v={1,2,7,11,15,5,9};
    int target = 18;


    pair<int, int> ans = PairSum(v, target);

    cout<<ans.first<<" "<<ans.second;
}