#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<double, int>p1, pair<double, int>p2){
    return p1.first>p2.first;
}

int  getFractionalKnapsack (vector<int> &value, vector<int>&weight , int W){
    vector<pair<double, int>> ratio;

    // first calculate value/weight
    for(int i =0; i<value.size(); i++){
        double r = value[i]/(double)weight[i];

        ratio.push_back(make_pair(r, i));
    }

    // now sort the array in desending order
    sort(ratio.begin(), ratio.end(), compare);

    int ans =0;

    // 3 now calculate the total value of the item that can we fill in the bag
    for(int i =0; i<value.size(); i++){
        int w = weight[i];
       

        if(w<W){
            ans+=value[i];
            W-=w;
            
        }
        else{
            ans+=(int)ratio[i].first*W;
            W=0;
            break;
        }

    }

    cout<<"total item value is "<<ans<<endl;
    return ans;
}
int main(){
    vector<int> value = {60,100,120};
    vector<int> weight = {10,20,30};
    int W = 50;
    cout<<getFractionalKnapsack(value, weight, W);
}