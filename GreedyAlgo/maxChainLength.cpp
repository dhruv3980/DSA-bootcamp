#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int>p1, pair<int , int>p2){
    return p1.second<p2.second;
}

int maxchainlength(vector<pair<int, int>>pairs){

    // FIRST SORT THE PAIRS VECTOR ON THE BASES OF END TIME
    sort(pairs.begin(), pairs.end(), compare);

    // now loop on the pairs to calculate the maxchain  lenght
    int ans =1;
    int endTime = pairs[0].second;
    for(int i=1; i<pairs.size(); i++){
        if(pairs[i].first>=endTime){
            ans++;
            endTime=pairs[i].second;
        }

    }
    cout<<"max-chain-length "<<ans;
    return ans;
}

int main(){
    int n=5;
    vector<pair<int, int>>pairs(n);
    pairs[0] = make_pair(5,24);
    pairs[1] = make_pair(39,60);
    pairs[2] = make_pair(5,28);
    pairs[3] = make_pair(27,40);
    pairs[4] = make_pair(50,90);

    maxchainlength(pairs);

}