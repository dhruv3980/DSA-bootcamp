#include<iostream>
using namespace std;
int tilingProblem(int n){
    // base case
    if(n==0 || n==1) return 1;

    int ans = tilingProblem(n-1)+ tilingProblem(n-2);
    return ans;

};
int main(){
    int n=5;
    cout<<"total No of ways to fill the board "<<tilingProblem(n);
}