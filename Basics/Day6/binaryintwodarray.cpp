#include<iostream>
using namespace std;
bool bsearch(int arr[][4],int rows, int cols, int r){
    int i=0;
    int j = rows*cols-1;
    int mid = i+(j-i)/2;
    while(i<=j){
        int a=mid/cols;
        int b=mid%cols;
        int element = arr[a][b];
        if(element==r){
            cout<<"element found at index"<<a<<b<<endl;
            return true;
        }
        if(element<r){
            i=mid+1;
        }
        else{
            j=mid-1;
        }
        mid=i+(j-i)/2;
    }
    return false;

}
int main(){
    int arr[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16},{17,18,19,20}};
    bool a = bsearch(arr,5,4,16);
    cout<<a;

}