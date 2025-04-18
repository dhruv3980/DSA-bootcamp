#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std ;
vector<bool>sieve(int n){
    vector<bool>primes(n+1,true);
    primes[0]=primes[1]=false;
    for(int i =2; i<=n ; i++){
        if(primes[i]){
            int j = i*i;
            while(j<=n){
                primes[j]=false;
                j+=i;
            }
        }
    }
    return primes;



}

vector<bool>segsieve(int L , int R){
    vector<bool> primes = sieve(sqrt(R));
    vector<int>helper;
    for(int i =0; i<primes.size(); i++){
        if(primes[i]){
            helper.push_back(i);
        }
    }
    vector<bool>segsiev(R-L+1,true);
    if(L==1|| L==0){
        segsiev[L]=false;
    }
    for(auto prime:helper){
        int first_mul =(L/prime)*prime;
        if(first_mul<L){
            first_mul+=prime;
        }
        int j = max(first_mul,prime*prime);
        while(j<=R){
            segsiev[j-L]=false;
            j+=prime;
        }

    }
    return segsiev;

}
int main(){
    vector<bool>ans= segsieve(110,130);
    int a =1;
    for(int i =0 ; i<ans.size(); i++){
        if(ans[i]){
            a=a*(i+110);
        }
    }
    cout<<a;

}