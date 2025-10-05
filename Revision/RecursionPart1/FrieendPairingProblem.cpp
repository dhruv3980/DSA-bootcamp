#include<iostream>
#include<string>
using namespace std;
int friendPairingProblem(int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }

    return friendPairingProblem(n-1)+(n-1)*friendPairingProblem(n-2);
}
int main(){

   int ans= friendPairingProblem(3);
   cout<<ans;

}