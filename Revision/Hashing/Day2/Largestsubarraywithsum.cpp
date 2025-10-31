#include<iostream>
#include<unordered_map>
using namespace std;

int largestSubarraywithSum(int arr[], int size){ // here i am find the max lenght of the subarray
    int sum =0;
    int ans=0;

    unordered_map<int, int>m; // first one is stored the value and second one stored the index

    for(int i=0; i<size; i++){
        sum+=arr[i];
        if(m.count(sum)){

            int idx = i-m[sum];

            ans = max(ans, idx);
            

        }else{
            m[sum]=i;
        }





    }




    return ans;

};
int main(){
    // int arr[]={15,-2,2,-8,1,7,10};
    int arr[] = {0, 0, 0, 0,0,0,0};

    int size =7;


    cout<<largestSubarraywithSum(arr, size);
}