#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector<int> previoussmaller(vector<int>& arr ){
    vector<int>ans(arr.size(), 0);
    stack<int>s;

    for(int i=0; i<arr.size(); i++){
        while(s.size()>0 && s.top()>=arr[i]){
            s.pop();

        }
        if(s.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = s.top();
        }

        s.push(arr[i]);
    }

    return ans;
}
int main(){

    vector<int>nums = {1,4,6,8,4,5,5};

    vector<int>ans = previoussmaller(nums);

    for(int i =0; i<ans.size(); i++){
        cout<<ans[i]<< " ";
    }

}