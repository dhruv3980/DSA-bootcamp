#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int fractionalkanpsack(vector<int>profit, vector<int> weight, int W){
    vector<pair<double, int>>valuebyweight;

    for(int i=0; i<profit.size(); i++){
        double p = double(profit[i])/weight[i];

        valuebyweight.push_back(make_pair(p, i));
    }


    sort(valuebyweight.begin(), valuebyweight.end());

    int ans =0;

   for(int i=valuebyweight.size()-1; i>=0; i--){
    if(W>=weight[valuebyweight[i].second]){
        ans+=profit[valuebyweight[i].second];

        W-=weight[valuebyweight[i].second];

    }
    else{
        ans+=int(valuebyweight[i].first)*W;

        W-=weight[valuebyweight[i].second];

    }
   }

   return ans;

}
int main(){
    vector<int>value = {60,100,120};
    vector<int> weight = {10,20,30};
    int w= 50;

    cout<<fractionalkanpsack(value, weight,w );
}