#include<iostream>
#include<vector>
using namespace std;
bool checksort(vector<int>&arr, int &size, int i){
    if(i==size-1){
        return true;
    }

    if(arr[i+1]<arr[i]){
        return false;
    }
    return checksort(arr, size, i+1);

}
int main(){
    vector<int>a{1,2,3,4,5,6};
    int i=0;
    int size= a.size();
    bool ans = checksort(a, size, i);
    if(ans){
        cout<<"array is sorted";
    }
    else{
        cout<<"array is not sorted";
    }
}