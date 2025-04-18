#include<iostream>
#include<vector>
using namespace std ;
void searchkey(int arr[][4], int row, int col, int key){
    for(int i=0; i<row; i++){
        for(int j=0 ; j<col; j++){
            if(arr[i][j]==key){
                cout<<"Key is found ";
                return;
            }
        }
    }
}
int main(){
    int arr[3][4];
    cout<<"Taking an element in the array";
    for(int i=0 ; i<3; i++){
        for(int j=0 ; j<4; j++){
            cin>>arr[i][j];
        }
    }

    int key;
    cout<<"Enter the key you want to search";
    cin>>key;
    searchkey(arr,3,4,key);
}