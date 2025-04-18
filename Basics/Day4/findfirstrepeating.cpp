#include<iostream>
#include<limits.h>
using namespace std;


int repeating(int arr[], int size){
    int max=INT_MIN;
    for(int i=0; i<size; i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    
    int hash[max + 1]={0};
    int a= sizeof(hash)/sizeof(int);
    for(int i=0; i<size; i++){
        hash[arr[i]]++;
    }
    
    for(int i=0; i<size; i++){
        if(hash[i]>1){
            return i+1;
        }
    }
    return -1;
}
int main(){
    int arr[]={1,2,5,3,5,4,6,9,7};
    int size=sizeof(arr)/sizeof(int);
    int r=repeating(arr,size);
    cout<<r;
}