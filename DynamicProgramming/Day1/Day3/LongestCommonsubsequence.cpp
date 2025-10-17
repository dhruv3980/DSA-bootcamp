#include<iostream>
using namespace std;

int lcs(string a, string b){
    if(a.size()==0 || b.size()==0){
        return 0;
    }

    int n=a.size();
    int m=b.size();

    if(a[n-1]==b[n-1]){
        return 1+lcs(a.substr(0, n-1), b.substr(0, m-1));


    }else{
        int ans1=lcs(a, b.substr(0, m-1));
        int ans2=lcs(a.substr(0,n-1), b);

        return max(ans1, ans2);
    }
}
int main(){
    string a="abcdge";
    string b = "abedg";

    int ans = lcs(a, b);
    cout<<ans;
}