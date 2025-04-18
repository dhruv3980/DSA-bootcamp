#include<iostream>
using namespace std;
int binarysearch(int arr[],int size, int target){
    int start=0;
    int end=size-1;
    int mid = start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==target){ //element found
            return mid;
        }
        else if(arr[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid = start+(end-start)/2;
    }
    return -2;

}
int main(){
    int arr[]={1,2,3,4,5,6,7};
    int size = 7;
    int target=11;
    
    int idx = binarysearch( arr, size, target);
    if(idx==-2){
        cout<<"element not found in any index ";
    }
    else {
        cout<<"element found at index "<<idx;
    }
}