#include<iostream>
using namespace std;
int partition(int*arr, int start, int end){

    int pivotidx=start;
    int pivotelement = arr[start];

    // count the element so that pivot is placed its correct position
    int count=0;
    for(int i=start+1; i<=end; i++){
        if(arr[i]<pivotelement){
            count++;
        }

    }
    int rightidx = start+count;

    swap(arr[start], arr[rightidx]);
    pivotidx=rightidx;

    int i = start;
    int j = end;

    while(i<pivotidx && j>pivotidx){
        while(arr[i]<=pivotelement){
            i++;
        }
        while(arr[j]>pivotelement){
            j--;
        }
        // 2 case ho sakte hain
        // A-> found the element to swap

        //B-> no need to swap

        if(i<pivotidx && j>pivotidx){
            swap(arr[i],arr[j]);
        }

    }
    return pivotidx;


}
void quicksort(int* arr, int start, int end){
    // base case
    if(start>=end){
        return;
    }

    int pivot = partition(arr,start,end);

    //left call
    quicksort(arr,start,pivot-1);
    quicksort(arr,pivot+1, end);



}
int main(){
    // int arr[]={5,9,4,15,3,15,14,7};
    int arr[]={5, -9, 4, 15, -3, 15, 14, 7};
    int Start=0;
    int end = 7;

    quicksort(arr,Start,end);

    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<endl;

}