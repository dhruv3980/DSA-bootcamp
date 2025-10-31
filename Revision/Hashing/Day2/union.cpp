#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;

void printunion (vector<int>arr1, vector<int>arr2){
    set<int>m;

    for(auto it:arr1){
        m.insert(it);
    }

    for(auto it:arr2){
        m.insert(it);
    }

    for(auto it: m){
        cout<<it<<" ";
    }
}

void printIntersection(vector<int>arr1, vector<int>arr2){
    unordered_set<int>m;

    for(auto it:arr1){
        m.insert(it);
    };


    for(auto it:arr2){
        if(m.find(it)!=m.end()){
            cout<<it<<" ";
            m.erase(it);
        }
    }
}
int main(){
    vector<int>arr1 = {7,3,9};
    vector<int>arr2={6,3,9,2,9,4};

    printunion(arr1, arr2);
    cout<<endl;

    printIntersection(arr1, arr2);
}