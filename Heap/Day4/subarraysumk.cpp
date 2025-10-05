#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraysumwithk(vector<int>arr, int k){
    unordered_map<int, int>m;
    int ans=0;
    int sum=0;

    m[0]=1;

    for(int i=0; i<arr.size(); i++){
        sum+=arr[i];
       
        if(m.count(sum-k)){
            
            ans+=m[sum-k];

        }
        else{
            if(m.count(sum)){
                m[sum]++;

               

            }else{
                m[sum]=1;

            }
        }

    }

  
    return ans;
}
int main(){
    vector<int>arr={10,3,-3,2,-2,-20,10};

    int ans =subarraysumwithk(arr,-10);

    cout<<ans;

}