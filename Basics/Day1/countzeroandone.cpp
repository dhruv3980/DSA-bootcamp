#include<iostream>
using namespace std;
int main(){
    int arr[]={0,1,0,1,0,1,1,1};
    int size=8;
    int countzero=0;
    for(int i=0 ; i<size; i++){
        if(arr[i]==0){
            countzero++;
        }
    }
    
    cout<<"no of zero's"<<countzero;
    cout<<"no of one's"<<(size-countzero);

}