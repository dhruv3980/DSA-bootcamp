#include<iostream>
using namespace std;
int * solve (){
    int a =25;
    int* ans = &a;
    cout<<ans<<endl;
    return ans;
}
int main(){
    int* p = solve();
    cout<<p;
}