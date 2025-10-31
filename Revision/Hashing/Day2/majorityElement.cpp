#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int majorityElement(vector<int>arr){
    unordered_map<int, int>m; // first one stored the number and second one stored the freq
    for(auto it:arr){
        if(m.count(arr[it])){
            m[it]++;

        }else{
            m[it]=1;
        }

    }

    for(auto it: m){

        if(it.second>=arr.size()/3){
            return it.first;
        }

    }

    return -1;


    
}
int main(){

    vector<int> arr ={1,3,2,5,1,3,1,5,1,2,2};

    cout<<"Majority Element is "<<majorityElement(arr);

    
}