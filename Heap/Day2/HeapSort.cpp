#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int>&arr, int idx, int size){
   

    int left =2*idx+1;
    int right= 2*idx+2;

    int maxidx = idx;

    if(left<size && arr[maxidx]>arr[left]){
         maxidx = left;

    
    }
    if(right<size && arr[maxidx]>arr[right]){
         maxidx =right; 
    }

    if(maxidx!=idx){
        swap(arr[maxidx], arr[idx]);
        heapify(arr, maxidx, size);
    }

}

void HeadSort(vector<int>&arr){
    int n= arr.size();

    for(int i=n/2-1; i>=0; i--){
        heapify(arr, i, n);

    }

    for(int i=n-1; i>=0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, 0,i);

    }


}
int main(){
    vector<int>arr{1,4,2,5,3};
    HeadSort(arr);
    for(int val:arr){
        cout<<val<<" ";
    }

}