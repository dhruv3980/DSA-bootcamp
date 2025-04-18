#include<iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,7};
    int size =7;
    int i=0; 
    int j=size-1;
    while(i<j){
        // if(i==j){
        //     break;
        // }
        // arr[i] =arr[i]+arr[j];
        // arr[j]=arr[i]-arr[j];
        // arr[i]=arr[i]-arr[j];

        arr[i] = arr[i] ^ arr[j];
        arr[j] = arr[i] ^ arr[j];
        arr[i] = arr[i] ^ arr[j];

        i++;
        j--;

    }
    for(int i=0 ; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int a = sizeof(arr)/sizeof(arr[0]);
    cout<<a;
}