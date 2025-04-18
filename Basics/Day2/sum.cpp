#include<iostream>
#include<vector>
using namespace std;
void printsum(int arr[][4], int row, int col){
    for(int i=0; i<col; i++){
        int sum=0;
        for(int j=0 ; j<row; j++){

            sum+=arr[j][i];
        }
        cout<<sum<<endl;
    }
}
int main(){
    int arr[3][4];
    cout<<"taking input in an array";
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"printing sum of an array column wise"<<endl;
    printsum(arr,3,4);
}