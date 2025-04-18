#include<iostream>
#include<vector>
using namespace std;
int findmin(vector<int>arr, int n, int minidx=0){
    if(n==0){
        return minidx;
    }
    if(arr[n-1]<arr[minidx]){
        minidx=n-1;
        
    }
    return findmin(arr,n-1,minidx);
}
int main(){
    vector<int>v{5,8,97,5,6,2,31};
    int ans =findmin(v,v.size());
    cout<<ans;
}