#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int countDistinct(vector<int>&arr){
    unordered_set<int>m;
    
    for(int i=0; i<arr.size(); i++){
        m.insert(arr[i]);
    }

    for(auto i:m){
        cout<<i<<endl;
    }


    
    return m.size();


    
}
int main(){
    vector<int>arr={1,4,2,2,3,4,5,6,7};

    

    cout<<countDistinct(arr);



}