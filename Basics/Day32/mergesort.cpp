#include<iostream>
using namespace std;
void merge(int* arr, int start, int end){
    int mid = start+(end-start)/2;
    int len1= mid-start+1;
    int len2= end - mid;

    int* leftarray = new int[len1];
    int* rightarray = new int [len2];


    int k = start;
    for(int i=0 ; i<len1; i++){
        leftarray[i]=arr[k];
        k++;
    }
    k = mid+1;
    for(int i =0; i<len2; i++){
        rightarray[i] = arr[k];
        k++;
    }

    int lai =0;

    int rai = 0;
    int arrayidx = start;

    while(lai<len1 && rai<len2){
        if(leftarray[lai]<rightarray[rai]){
            arr[arrayidx++]=leftarray[lai++];
        }
        else{
            arr[arrayidx++]=rightarray[rai++];
        }


    }
    
    while(lai<len1){
        arr[arrayidx++]= leftarray[lai++];
    }
    while(rai<len2){
        arr[arrayidx]=rightarray[rai];
        arrayidx++;
        rai++;
    }


}
void mergesort(int* arr, int start, int end){
    // base case
    if(start>=end){
        return;
    }

    int mid = start+(end-start)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1, end);


    merge(arr,start,end);
}
int main(){
    int arr[]={38,27,43,3,9,20};
    int size=sizeof(arr)/sizeof(int);


    mergesort(arr,0,size-1);
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }

}
