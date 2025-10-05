#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int>profit, vector<int>weight, int n , int capacity){
    vector<vector<int>>dp(n+1, vector<int>(capacity+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=capacity; j++){
            int itemweight = weight[i-1];
            int itemprofit = profit[i-1];

            if(itemweight<=j){
                dp[i][j]=max(itemprofit+dp[i][j-itemweight], dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    return dp[n][capacity];

}
int main(){
    vector<int>profit={15,14,10,45,30};
    vector<int> weight = {2,5,1,3,4};

    int n=5;
    int capacity=7;

   int ans= knapsack(profit, weight, n, capacity );
   cout<<ans;
}