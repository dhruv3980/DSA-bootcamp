#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Lcsmemo(string a, string b, vector<vector<int>>&dp){
    if(a.size()==0 || b.size()==0){
        return 0;
    }

    int n=a.size();
    int m=b.size();

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    if(a[n-1]==b[n-1]){
        dp[n][m]=1+Lcsmemo(a.substr(0, n-1), b.substr(0, m-1), dp);

    }
    else{
        dp[n][m]=max(Lcsmemo(a.substr(0, n-1), b, dp),  Lcsmemo(a, b.substr(0, m-1), dp));

        

    }

    return dp[n][m];

}
int main(){
    string a = "abcdge";
    string b="abedg";

    vector<vector<int>>dp(a.size()+1, vector<int>(b.size()+1, -1));

    int ans = Lcsmemo(a, b, dp);
    cout<<ans;
}