#include<iostream>
#include<vector>
using namespace std;
int findidx(vector<int>arr, int n, int maxidx=0){
    if(n==0){
        return maxidx;
    }
    if(arr[n-1]>arr[maxidx]){
        maxidx=n-1;
    }
    return findidx(arr,n-1,maxidx);

}
int main(){
    vector<int>v{5,4,8,9,2,3};
    int a=v.size();
    int ans = findidx(v,a);
    cout<<ans;
}