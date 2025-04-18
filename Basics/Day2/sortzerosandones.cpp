#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr{0,1,0,1,1,1,1};
    int start=0;
    int end = arr.size()-1;
    while(start<end){
        if(arr[start]==0){
            start++;
        }
        else{
            swap(arr[start],arr[end]);
            end--;
        }
    }
    for(int ans:arr){
        cout<<ans<<" ";
    }

}