#include<iostream>
using namespace std;

int search(int arr[], int start, int end, int target){
    if(start>end){
        return -1;
    }

    

  

    int mid = start+(end-start)/2;

   

    if(arr[mid]==target){
        return mid;
    }

    if(arr[start]<=arr[mid]){
        if(arr[start]<=target&& target<=arr[mid]){
            return search(arr, start, mid-1, target);
   
        }
        else{
            return search(arr, mid+1, end, target);
             
        }

    }
    else{
        if(arr[mid]<=target && target<=arr[end]){
            return search(arr, mid+1, end, target);
            
        }
        else{
            return search(arr, start, mid-1, target);
             
        }
    }
}
int main(){
    int arr[]={4,5,6,7,0,1,2,3};
    int n=8;


    cout<<"Idx is "<<search(arr, 0, n-1, 3);
}