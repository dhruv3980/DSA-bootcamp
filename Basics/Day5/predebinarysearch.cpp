#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>a{1,2,3,4,5,67,7};
    if(binary_search(a.begin(), a.end(),8)){
        cout<<"element found";
    }
    else{
        cout<<"not found";
    }
}