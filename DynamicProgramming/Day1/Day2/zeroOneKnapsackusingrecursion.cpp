#include<iostream>
#include<vector>
using namespace std;
int knapsack(vector<int>profit, vector<int>weight, int n, int capacity, vector<vector<int>>&dp){ // solve using memorization
    if(n==0 || capacity==0){
        return 0;
    }

    if(dp[n][capacity]!=-1){
        return dp[n][capacity];
    }

    if(weight[n-1]<=capacity){ // accept
        int ans1 = knapsack(profit, weight, n-1, capacity-weight[n-1], dp)+profit[n-1];
        int ans2= knapsack(profit, weight, n-1, capacity, dp);

        dp[n][capacity]= max(ans1, ans2);
    }else{
        dp[n][capacity]= knapsack(profit, weight, n-1, capacity, dp);

    }
    return dp[n][capacity];
}

// int recursiontab(vector<int>profit, vector<int>weight, int n , int capacity){

//     vector<vector<int>>dp(n+1, vector<int>(capacity+1, 0));
    
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=capacity; j++){
            
//             if(weight[i-1]<=j){

//                 dp[i][j]=max(profit[i-1]+dp[i-1][j-weight[i-1]], dp[i-1][j]);

//             }
//             else{
//                 dp[n][capacity]=dp[i-1][j];
//             }
//         }
//     }

//     for(int i=0; i<n+1; i++){
//         for(int j=0; j<capacity+1; j++){
//             cout<<dp[i][j]<<" ";
//         }
//         cout<<endl;
//     }

//     return dp[n][capacity];
// }


int recursionTab(vector<int>value, vector<int> weight , int n , int capacity){

    vector<vector<int>>dp(n+1, vector<int>(capacity+1, 0));
    

    for(int i=1; i<n+1; i++){
        for(int j=1; j<capacity+1; j++){
            
            int itemval = value[i-1];
            int itemweight = weight[i-1];

            if(itemweight<=j){
                dp[i][j]=max(itemval+dp[i-1][j-itemweight], dp[i-1][j]);

            }
            else{
                dp[i][j]=dp[i-1][j];

            }
        
        }
    }

    for(int i=0; i<n ; i++){
        for(int j=0; j<capacity; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][capacity];
};
int main(){

    int capacity = 7;
    
    vector<int>profit={15,14,10,45,30};
    vector<int> weight = {2,5,1,3,4};
    int n=5;

    vector<vector<int>>dp(n+1, vector<int>(capacity+1, -1));

    int ans = knapsack(profit, weight, n, capacity, dp);

    int ans2 = recursionTab(profit, weight, n, capacity);

    cout<<ans<<ans2;

}