#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void printmejorityElement (int arr[], int size){
    unordered_map<int, int>ans;
    for(int i=0; i<size; i++){
        if(ans.count(arr[i])){
            ans[arr[i]]++;

        }else{
            ans[arr[i]] = 1;
        }

    

    };

    for(auto val:ans){
        if(val.second>size/3){

             cout<<val.first<<" ";
        }
       
    }
    cout<<endl;
}
int main(){
    int arr[9] = {1,2,3,5,1,3,1,5,1};
    int arr2[]={1,2};

    printmejorityElement(arr, 9);
    printmejorityElement(arr2, 2);

}