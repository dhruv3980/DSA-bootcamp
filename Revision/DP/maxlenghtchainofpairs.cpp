#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxlenghtchainofpairs(vector<pair<int, int>> pairs){
    // sort on the bases of end

    sort(pairs.begin(), pairs.end(), [](pair<int, int>&a, pair<int, int> &b){
        return a.second<b.second;
    });

    int ans =1;

    int safer = pairs[0].second;

    for(int i=1; i<pairs.size(); i++){
        if(pairs[i].first>=safer){
            safer=pairs[i].second;
            ans++;
        }
    }

    return ans;


}
int main(){

    vector<pair<int, int>>pairs;
    pairs.push_back(make_pair(5,24));
    pairs.push_back(make_pair(39,60));
    pairs.push_back(make_pair(5,28));
    pairs.push_back(make_pair(27,40));
    pairs.push_back(make_pair(50,90));


    int ans = maxlenghtchainofpairs(pairs);
    cout<<ans;


}