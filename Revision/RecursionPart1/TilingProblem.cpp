#include<iostream>
using namespace std;

int titlingproblemtotalways(int n){
    if(n==1 ) return 1;
    if(n==2) return 2;

    return titlingproblemtotalways(n-1)+titlingproblemtotalways(n-2);
}
int main(){
    int n=5;
    int ans=titlingproblemtotalways(n);
    cout<<ans;
}