#include<iostream>
#include<vector>
using namespace std;
int getminchange(vector<int>&coins, int V){
    int ans=0;
    for(int i = coins.size(); i>=0 && V>0 ; i--){
        
        if(coins[i]<=V){
            
            ans+=V/coins[i];
            
            V=V%coins[i];
        }

    }

    cout<<"min coin that can we used to make the val  "<<ans;
    return ans;
}
int main(){
    vector<int> coins{1,2,5,10,20,50,100,500,2000};
    int V = 590;
    getminchange(coins,V);

}