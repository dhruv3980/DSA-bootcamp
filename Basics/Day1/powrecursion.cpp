#include<iostream>
using namespace std;

int ans(int x, int n){
    if(n==0) return 1;

    int leftans = ans(x, n/2);
    int square = leftans*leftans;

    if(n%2!=0){
        return x*square;
    }
    return square;
}
int main(){

    int ans1 = ans(2,5);
    cout<<ans1;

}