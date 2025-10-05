#include<iostream>
#include<vector>
using namespace std;
int fibtab(int n){
    vector<int>fib(n+1, 0);//meaning assign ith index store the ith fibnacci number

    fib[0]=0;
    fib[1]=1;

    for(int i=2; i<=n; i++){
        fib[i]=fib[i-1]+fib[i-2];
       

    }

   
    return fib[n];
}
int main(){
    int n=6;
    int ans=fibtab(n);
     cout<<ans;
}

// 3-steps
//first one is chhose a data structure to store and 2 is assign the meaning and third is store the smallest problem ans and then calculate from small to large