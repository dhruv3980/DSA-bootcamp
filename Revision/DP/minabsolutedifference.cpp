#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minabsolutediffernece(vector<int> firs, vector<int>second){
    int ans =0;

    sort(firs.begin(), firs.end());
    sort(second.begin(), second.end());


    for(int i=0; i<firs.size(); i++){
        ans+=abs(firs[i]-second[i]);
    }

    return ans;

}
int main(){
    vector<int> first = {1,2,3};
    vector<int>second= {2,1,3};

    cout<<minabsolutediffernece(first, second);

}