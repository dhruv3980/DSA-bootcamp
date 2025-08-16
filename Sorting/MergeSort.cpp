#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr, int start , int mid, int end){
    vector<int>temp;
    int i = start;
    int j = mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;

        }
        else{
            temp.push_back(arr[j]);
            j++;
        }

    }
    while(i<=mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx =0; idx<temp.size(); idx++){
        arr[idx+start] = temp[idx];

    }
}
void mergesort(vector<int>&a, int start, int end){
    if(start<end){
        int mid = start+(end-start)/2;

        // left call
        mergesort(a, start, mid);

        // right call
        mergesort(a, mid+1, end);

        merge(a, start, mid, end);




    }
   
    
}
int main(){
    vector<int>a{5,1,7,9,5,4,2,3};
    mergesort(a, 0,7);

    for(int ele:a){
        cout<<ele<<" ";
    }
}