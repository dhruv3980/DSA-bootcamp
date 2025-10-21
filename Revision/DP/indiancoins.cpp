#include<iostream>
#include<vector>
using namespace std;

int mincoinuse(vector<int>coins, int amount){
    int ans=0;
    for(int i=coins.size()-1; i>=0 && amount>0; i--){
        if(coins[i]<=amount){
          
            ans+=amount/coins[i];
            amount = amount%coins[i];

        }
    } 

    return ans;
}
int main(){
    vector<int>coins = {1,2,5,10,20,50,100,500,2000};

    int amount = 121;

    int ans = mincoinuse(coins, amount);
    cout<<ans;
}