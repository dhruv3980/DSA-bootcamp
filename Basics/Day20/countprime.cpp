#include<iostream>
#include<vector>
using namespace std ;
vector<bool>Sieve(int n){
    vector<bool>sieve(n,true);
    sieve[0]=sieve[1]=false;
    for(int i =2; i*i<=n; i++){
        if(sieve[i]==true){
            int j =i*i;
            while(j<=n){
                sieve[j]=false;
                j+=i;
            }
        }

    }
    return sieve;
}
int main(){
    int n=25;
    vector<bool>a = Sieve(n);
    int ans =0;
    for(int i=0; i<=25; i++){
        if(a[i]){
          ans+=i;

        }

    }
    cout<<ans;
}