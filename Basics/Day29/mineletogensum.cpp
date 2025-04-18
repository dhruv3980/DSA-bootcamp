#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int solve(vector<int>&arr, int target){
    if(target==0){
        return 0;

    }
    if(target<0){
        return INT_MAX;
    }

    int ans= INT_MAX;
    for(int i=0; i<arr.size(); i++){
        int mini = solve(arr, target-arr[i]);
        if(mini!=INT_MAX){
            ans= min(ans,mini+1);

        }
    }
    return ans;
}
int main(){
    vector<int>a{1,2,3,4};
    int target=11;

    int ans = solve(a, target);

    cout<<ans;


}