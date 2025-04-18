#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
int findmax(int arr[][3], int row, int col){
    int m=INT_MAX;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j]<m){
                m=arr[i][j];
            }
        }
    }
    return m;
}
int main(){
    int arr[3][3];
    cout<<"taking input in array";
    for(int i=0; i<3;i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }
    int a= findmax(arr,3,3);
    cout<<"Minimum Element is "<<a;
}