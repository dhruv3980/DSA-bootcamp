#include<iostream>
using namespace std;
// int find(int arr[], int target){ //O(logn)
//     int i=0;
//     int ans =-1;

//     while(arr[i]<=target){
//         if(arr[i]==target){
//             ans=i;
//             break;
//         }
//         else {
//             i++;
//         }
//     }
//    if(i==-1){
//     return -1;
//    }
//    else if(arr[i]==target){
//     return i;
//    }
//    else{
//     return -1;
//    }

// }
int binarysearch(int arr[], int start,int end,int target){
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid]==target){
            return mid;
        }
        if(arr[mid]<target){
            start=mid+1;
        }
        else{
            end= mid-1;

        }
        mid=start+(end-start)/2;

    }
    return -1;
}

int find(int arr[], int target){
    int i=0;
    int j=1;

   while(arr[j]<=target){
    j=j*2;
   }
   return binarysearch(arr,i,j,target);

}
int main(){
    int arr[]={2,3,6,7,8,9,10,12,15};
    int ans = find (arr,15);
    cout<<ans;
}


// day 8 making coding with me 