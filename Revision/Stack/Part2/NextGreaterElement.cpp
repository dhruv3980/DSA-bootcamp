#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void nextgreaterElement(vector<int>arr, vector<int>ans){
    int n = arr.size();
    stack<int>s;
    ans[n-1]=-1;
    s.push(arr[n-1]);

    for(int i=n-2; i>=0; i--){
        int current = arr[i];

        while(!s.empty() && s.top()<=current){
            s.pop();
        }

        if(s.empty()){
            s.push(current);
            ans[i]=-1;
        }else{
            ans[i]=s.top();
            s.push(current);
        }
    }


    for(int i=0 ; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    

}
int main(){
    vector<int>arr={6,8,0,1,3};
    vector<int>ans(5);

    nextgreaterElement(arr, ans);
}