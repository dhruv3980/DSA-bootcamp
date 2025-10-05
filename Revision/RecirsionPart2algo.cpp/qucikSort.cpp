#include<iostream>
#include<vector>
using namespace std;

int partition(int arr[], int start, int end){
    int i=start-1;

    int j=start;

    int pivot=end;

    while(j<end){
        if(arr[j]<=arr[pivot]){

            
            swap(arr[++i], arr[j++]);
           
            
        }
        else{
             j++;

        }
       
    }

    ++i;
    swap(arr[i], arr[pivot]);

    return i;

}

void quicksort(int arr[], int start, int end){
    if(start>=end) return;

    int partitionidx  = partition(arr, start, end);

  

    

    quicksort(arr, start, partitionidx-1);
    quicksort(arr, partitionidx+1, end);
}

void print(int arr[], int n){
    for(int i=0; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[]={1,2,3,4,5,6};
    int start =0;
    int end=5;

    quicksort(arr, start, end);
    print(arr, end);
}