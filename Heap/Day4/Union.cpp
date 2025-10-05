#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void Union(vector<int>arr1, vector<int>arr2){
    unordered_set<int>m;
    for(auto el:arr1){
        m.insert(el);
    }
    for(auto el:arr2){
        m.insert(el);
    }

    for(auto el:m){
        cout<<el<<" ";
    }


    
};

void intersection(vector<int>arr1, vector<int>arr2){
    unordered_set<int>m;

    for(auto el:arr1){
        m.insert(el);
    }

    for(auto el: arr2){
        if(m.find(el)!=m.end()){
            cout<<el<<" ";
            m.erase(el);

        }
    }

}
int main(){
    vector<int>arr1={7,3,9};
    vector<int>arr2={6,3,9,2,9,4};
    Union(arr1, arr2) 
    ;

    cout<<endl;

    intersection(arr1,arr2);
    

}