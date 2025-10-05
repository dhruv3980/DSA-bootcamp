#include<iostream>
#include<vector>
using namespace std;
int climbinstairs(int n){
    vector<int>ans(n+1, -1);

    ans[0]=1;
    ans[1]=1;
    ans[2]=2;

    for(int i=3; i<=n; i++){
        ans[i]=ans[i-1]+ans[i-2]+ans[i-3];
    }
    return ans[n];

}
int main(){

    int ans = climbinstairs(4);
    cout<<ans;

}