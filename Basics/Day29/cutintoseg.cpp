#include<iostream>
#include<limits.h>
using namespace std;
int segment (int n, int x,int y,int z){
    if(n==0){
        return 0;
    }
    if(n<0){
        return INT_MIN;
    }

    int ans1= segment(n-x,x,y,z)+1;
    int ans2=segment(n-y,x,y,z)+1;
    int ans3=segment(n-z,x,y,z)+1;

    int ans = max(ans1, max(ans2,ans3));
    return ans;

}
int main(){
    int n=7;
    int x=5;
    int y=2;
    int z=2;
    int ans = segment(n,x,y,z);
    cout<<"max segment is "<<max(ans,0);
}