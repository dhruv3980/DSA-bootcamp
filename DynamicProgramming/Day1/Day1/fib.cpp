#include<iostream>
#include<vector>
using namespace std;
int fib(vector<int>&f, int n){
    if(n==0|| n==1){
        return n;
    }
    if(f[n]!=-1){
        return f[n];
    }
   

    f[n]= fib(f, n-1)+fib(f, n-2);
    return f[n];
}
int main(){
    vector<int>f(7,-1);
    int n=6;

    int ans=fib(f, n);
    cout<<ans;


}