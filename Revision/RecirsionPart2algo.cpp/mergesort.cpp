#include<iostream>
#include<vector>
using namespace std;

void merge(int arr[], int start, int end){
    vector<int>temp;
    int mid = start+(end-start)/2;

    int i=start;
    int j=mid+1;

    while(i<=mid && j<=end){
        if(arr[i]<arr[j]){
            temp.push_back(arr[i++]);
        }
        else{
            temp.push_back(arr[j++]);
        }

    }

    while(i<=mid){
        temp.push_back(arr[i++]);
    }

    while(j<=end){
        temp.push_back(arr[j++]);
    }

  
    
     i=start;

    for(int j=0;j<temp.size(); j++ ){
        arr[i++]=temp[j];
    }

}

void mergeSort(int arr[],  int start, int end){
    if(start>=end) return;

    int mid = start+(end-start)/2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);

    merge(arr, start, end);

}

void print(int arr[], int n){
    for(int i=0; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

}
int main(){
    int arr[]={6,3,7,5,2,4};
    int start =0;
    int end=5;

    mergeSort(arr, start, end);

    print(arr, end);
}