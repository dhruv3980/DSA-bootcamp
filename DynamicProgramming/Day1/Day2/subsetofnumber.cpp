#include<iostream>
#include<vector>
using namespace std;
bool sumsetOfNumber(vector<int>nums, int target){
    int n=nums.size();
    vector<vector<int>>dp(n+1, vector<int>(target+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=target ; j++){
            if(nums[i-1]<=j){

                dp[i][j]= max(nums[i-1]+dp[i-1][j-nums[i-1]], dp[i-1][j]);

            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    for(int i=0; i<=nums.size(); i++){
        for(int j=0; j<=target; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][target]==target;
}
int main(){
    vector<int> val = {4,2,7,1,3};
    int n=10;

    cout<<sumsetOfNumber(val, 7);
}