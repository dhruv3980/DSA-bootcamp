#include<iostream>
using namespace std;
void move(int arr[], int size){
    int low =0;
    int high=size-1;
    while(low<high){
        if(arr[low]<0){
            low++;

        }
        else if(arr[high]>0){
            high--;
        }
        else{
            swap(arr[low],arr[high]);
        }
    }
}
int main(){
    int arr[]={1,2,-1,3,4,-2};
    int size = sizeof(arr)/sizeof(int);
    move(arr,size);
    for(int val:arr){
        cout<<val<<" ";
    }
}