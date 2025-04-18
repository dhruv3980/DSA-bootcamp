#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,7};
    int size=7;
    int i=0;
    int j=size-1;
    while(i<=j){
        
        cout<<arr[i]<<" ";
        i++;
            if(i<j){
            cout<<arr[j]<<" ";
            j--;
        }
    }
}