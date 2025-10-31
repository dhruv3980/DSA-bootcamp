#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int largestsubarraycountwithsumk(vector<int>arr, int k){ // here we return the total no of subarray exist 
    int ans =0;
    int sum =0;
    unordered_map<int, int>m;
    m[0]=1;



    for(int i=0; i<arr.size(); i++){
        sum+=arr[i];

        if(m.count(sum-k)){
            ans+=m[sum-k];


        }

        if(m.count(sum)){
            m[sum]++;

        }else{
            m[sum]=1;
        }

    }

    return ans;





    return ans;

}
int main(){
    vector<int>arr={10,2,-2,-20,10};
    int k=-10;

    cout<<largestsubarraycountwithsumk(arr, k);

}