#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int countdistinct(vector<int>arr){
    unordered_set<int>ans;

    for(auto it: arr){
        ans.insert(it);

    }

    return ans.size();
}
int main(){
    vector<int>arr={4,3,2,5,6,7,3,4,2,1};

    cout<<countdistinct(arr);
}