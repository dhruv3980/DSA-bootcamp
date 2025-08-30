#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>p1 = {4,1,8,7};
    vector<int>p2={2,3,6,5};

    // now sort both the arr
    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());

    // now calculata ans
    int ans =0;
    for(int i=0; i<p1.size(); i++){
        ans+=abs(p1[i]-p2[i]);
    }

    cout<<"min abs difference "<<ans;

}