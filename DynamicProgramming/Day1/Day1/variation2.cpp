#include<iostream>
#include<vector>
using namespace std;

int climbingstairs(int n){
    vector<int>dp(n+1, -1);

    
    dp[1]=1;
    dp[2]=1;
    dp[3]=2;

    for(int i=4; i<=n; i++){
        dp[i]=dp[i-1]+dp[i-3];

    }
    return dp[n];
}

int main(){
    int n=5;
    int ans = climbingstairs(4);
    cout<<ans;

}