#include<iostream>
#include<vector>
using namespace std;
int missing(vector<int>v){
    int start=0;
    int end=v.size()-1;
    int mid= start+(end-start)/2;
    int ans =-1;
    while(start<=end){
        if(v[mid]==mid+1){
            start = mid+1;
        }
        else{
            ans=mid;
            end= mid-1;
        }
        mid= start+(end-start)/2;

    }
    if(ans==-1){
        return ans;
    }
    else{
        return ans+1;
    }
}
int main(){
    vector<int>v{1,2,3,4,5,6,7,8,9,11,12};
    int ans = missing(v);
    cout<<ans;
}