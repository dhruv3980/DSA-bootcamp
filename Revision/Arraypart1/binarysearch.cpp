#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key){  // binary search always work on sorted array
    int i=0; 
    int j=n-1;

    while(i<=j){
        int mid =i+(j-i)/2;

        if(arr[mid]==key) return mid;

        if(arr[i]<key){
            i=mid+1;
        }
        else{
            j=mid-1;
        }

    }
    return -1;
}
int main(){
    int arr[]={2,4,6,8,10,12,14};
    int n=7;

    int ans =binarySearch(arr, n, 10);

    if(ans!=-1){
        cout<<"Number exist";
    }else{
        cout<<"Not exist";
    }

    
}








// in c++ ptr1-ptr2 is valid but this is not valid ptr1+ptr2


