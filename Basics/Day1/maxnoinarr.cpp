#include<iostream>
#include<limits.h>
using namespace std;
int main(){
    int arr[]={1,2,3,14,5,6,17,8};
    int size = 8;
    
    int n= INT_MIN;
    for(int i=0; i<size; i++){
        if(arr[i]>n){
           
            n=arr[i];

        }

    }
    cout<<n;
}