#include<iostream>
#include<vector>
using namespace std;

int maxprofit(vector<int>price, vector<int>length, int rodlenght){
    int n=length.size();

    vector<vector<int>>dp(n+1, vector<int>(rodlenght+1, 0));

    for(int i=1; i<n+1; i++){
        for(int j=1; j<rodlenght+1; j++){
            if(length[i-1]<=j){
                dp[i][j]=max(dp[i][j-length[i-1]]+price[i-1], dp[i-1][j]);

            }else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][rodlenght];

}
int main(){
    vector<int> price= {1,5,8,9,10,17,14,20};
    vector<int>piece={1,2,3,4,5,6,7,8};
    int rodlength=8;

    int ans = maxprofit(price, piece, rodlength);

    cout<<ans;
}