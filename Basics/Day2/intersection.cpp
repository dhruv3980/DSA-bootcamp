#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int>a{1,1,2,3,4,5};
    vector<int>b{1,2,1,3,8};
    vector<int>ans;
    for(int i=0 ; i<a.size(); i++){
        for(int j=0; j<b.size(); j++){
            if(a[i]==b[j]){
                ans.push_back(b[j]);
                b[j]=-1;
                
            }
        }
    }
    for(int i=0 ; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

}