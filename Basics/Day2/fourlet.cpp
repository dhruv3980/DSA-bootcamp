#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>arr{10,20,30,40,50,60,70,80,90,100};
    int sum=100;
    for(int i=0 ; i<arr.size(); i++){
        for(int j=i+1; j<arr.size();j++){
            for(int k=j+1; j<arr.size(); k++){
                for(int l= k+1; l<arr.size(); l++){
                    if(arr[i]+arr[j]+arr[k]+arr[l]==sum){
                        cout<<"fourlet is "<<arr[i]<<","<<arr[j]<<","<<arr[k]<<","<<arr[l]<<endl;
                    }
                }
            }
        }
    }
}