#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
void solve(vector<int>& v, int sum, int i, int& mini){
    if(i>=v.size()){
        mini = max(sum, mini);
        return;
    }

    // include
    solve(v,sum+v[i],i+2,mini);

    // exclude

    solve(v,sum, i+1, mini);
}

int main(){
    vector<int>v{2,1,4,9};
    int i=0;
    int sum=0;
    int maxi = INT_MIN;
    solve(v,sum,i,maxi);
    cout<<maxi;
}

    