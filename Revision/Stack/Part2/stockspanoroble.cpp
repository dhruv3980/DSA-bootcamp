#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void stockspanProblem(vector<int>&s, vector<int>& ans){
    

    stack<int>prevhigh;

    prevhigh.push(0);
    ans[0]=1;


    for(int i=1; i<s.size(); i++){
        int current = s[i];
        while(!prevhigh.empty() && s[prevhigh.top()]<=current){
            prevhigh.pop();
        }

        if(prevhigh.empty()){
            ans[i]=i+1;
            
        }else{
            ans[i]=i-prevhigh.top();
        }

        prevhigh.push(i);

    }

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }


}
int main(){
    vector<int> s = {100,80,60,70,60,85,100};
    vector<int> ans = {0,0,0,0,0,0,0};

    stockspanProblem(s, ans);

}