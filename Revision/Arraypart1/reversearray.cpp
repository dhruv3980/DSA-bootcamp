// #include<iostream>
// using namespace std;

// void reverse(int arr[], int n){
//     int reversearr[n];

//     int i=n-1;
//     int j=0;
//     while(i>=0){
//         reversearr[j++]=arr[i--];

//     }

//     for(int i=0; i<n; i++){
//         arr[i]=reversearr[i];
//     }

// }
// int main(){
//     int arr[]={5,4,3,2,1,4};
//     int n=6;

//     reverse(arr, n);

//     for(int i=0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
// }


#include<iostream>
using namespace std;
void reverse(int arr[], int n){
    int i=0, j=n-1;

    while(i<j){
        swap(arr[i], arr[j]);
        i++;
        j--;

    }
}

int main(){
    int arr[]={1,2,3,4,5};
    int n=5;

    reverse(arr, n);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}