#include<iostream>
#include<vector>
using namespace std;
void transposefun(int arr[][4], int row, int column, int transpose[][3]){
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            transpose[j][i]=arr[i][j];
        }
    }
}
int main(){
    int arr[3][4];
    cout<<"Enter the array element";
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cin>>arr[i][j];
        }
    }
    int transpose[4][3];
    transposefun(arr,3,4,transpose);

    for(int i=0;  i<4;i++){
        for(int j=0; j<3; j++){
            cout<<transpose[i][j]<<" ";
        }
        cout<<endl;
    }
}