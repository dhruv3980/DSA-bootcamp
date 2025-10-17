#include<vector>
#include<iostream>
using namespace std;

void backtrackArray(vector<int>&v, int n, int i){
    if(i==n){
        return;
    }

    v[i]=i+1;
    backtrackArray(v, n, i+1);

    v[i]-=2;

    
}
int main(){
    vector<int>v(5);

    backtrackArray(v, 5, 0);

    for(int i=0; i<5; i++){
        cout<<v[i]<<" ";
    }
}