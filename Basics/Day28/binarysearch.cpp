#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int>arr, int start, int end, int key){
    // base case 
    // case ->1 key not found

    if(start>end){
        return -100;
    }

    // case 2 -> key found;
    int mid= (end+start)/2;

    if(arr[mid]==key){
        
        return mid;
    }

    // mid<key seaech in right part

    if(arr[mid]<key){
        
        return binarysearch(arr, mid+1, end , key);
    }
    // mid>key search in left part

    else{
       
        return binarysearch(arr, start, mid-1,key);
    }
}
int main(){
    vector<int>v{10,20,30,40,60,70,90,99};
    int size=v.size();
    int start=0;
    int end=size-1;
    int key =99;
     
    int ans = binarysearch(v,start,end,key);

    cout<<"Element found at the index : "<<ans;

}