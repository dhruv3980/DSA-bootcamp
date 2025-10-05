#include<iostream>
#include<vector>
using namespace std;

void BinaryStringwithNoconsequitiveones(int n, int lastindex, string ans){
    if(n==0){
        cout<<ans<<endl;
        return;
    }

    if(lastindex!=1){
        BinaryStringwithNoconsequitiveones(n-1, 0, ans+'0');
        BinaryStringwithNoconsequitiveones(n-1, 1, ans+'1');

    }else{
         BinaryStringwithNoconsequitiveones(n-1,0, ans+'0');

    }
}
int main(){

    int n=3;

    BinaryStringwithNoconsequitiveones(n, 0, "");


}