#include<iostream>
#include<algorithm>
using namespace std;
int bsearch(int arr[], int start,int end ,int target){
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==target){
            return mid;

        }
        else if(arr[mid]<target){
            start = mid+1;
        }
        else{
            end =mid-1;
        }
        mid= start+(end-start)/2;
    }
    return -1;

}
int expsearch(int arr[], int size, int target){
    if(arr[0]==target){
        return 0;
    }
    int i=1;
    while(i<size && arr[i]<=target){
        i= i*2;
    }
    return bsearch(arr,i/2, min(i,size-1), target);
}
// time complexity O(2^(logm-1));
int main(){
    int arr[]={3,6,9,12,16,17,18,22,25,29,30};
    int target = 25;
    int n = sizeof(arr)/sizeof(int);
    int ans = expsearch(arr,n,target);
    cout<<ans;
}