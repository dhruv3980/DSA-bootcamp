#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int largestsubwithsumzero(vector<int>arr){
    int ans=0;
    int sum=0;

    unordered_map<int, int>m;

    for(int i=0; i<arr.size(); i++){
        sum+=arr[i];

        if(m.count(sum)){
            int currentlen = i-m[sum];
            ans=max(currentlen, ans);


        }else{
            m[sum]=i;

        }
        
    }

    return ans;
}
int main(){
    vector<int>arr={15,-2,2,-8,1,7,10};

    cout<<"Largest subarray with sum zero "<<largestsubwithsumzero(arr);
}