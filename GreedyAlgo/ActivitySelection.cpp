#include<iostream>
#include<vector>


using namespace std;
int maxActivitySelect(vector<int>&start, vector<int>&end){
    int ans = 1;
    
    int endtime = end[0];

    cout<<"Activity A0 select"<<endl;
    for(int i =1; i<start.size(); i++){
        if(start[i]>=endtime){
            endtime = end[i];
            cout<<"Activity A"<<i<<" Select"<<endl;
            ans++;
        }
    }
    return ans;
}
int main(){
    vector<int>start = {1,3,0,5,8,5};
    vector<int>end = {2,4,6,7,9,9};
    cout<<maxActivitySelect(start,end);
}