#include<iostream>
using namespace std;
void sort(int arr[],  int size){
    int low = 0;
    int high=size-1;
    while(low<high){
        if(arr[low]==0){
            low++;
        }
        else if(arr[high]==1){
            high--;
        }
        else{
            swap(arr[low],arr[high]);
        }
    }

}
int main(){
    int arr[]={1,0,1,0,1,1,1};
    int size=sizeof(arr)/sizeof(int);
    sort(arr,size);
    for(auto val:arr){
        cout<<val<<" ";
    }

}