#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool ispossibletomake(vector<int>cooksrank, int np , int mid){
    int currentparata=0;
    for(int i=0; i<cooksrank.size();i++){
        int r= cooksrank[i];
        int j=1;
        int timetaken=0;
        while(true){
            if(timetaken+r*j<=mid){
                currentparata++;
                timetaken+=j*r;
                j++;


            }
            else{
                break;
            }

        }
        if(currentparata>=np) return true;

    }
    return false;
    


}
int maxtimetaken(vector<int>cooksrank,int np){
    int start=0;
    int a = *max_element(cooksrank.begin(), cooksrank.end());
    int end= a*(a+1)/2;
    int mid = start+(end-start)/2;
    while(start<=end){
        if(ispossibletomake(cooksrank,np,mid)){
            end = mid-1;;

        }
        else{
            start=mid+1;
        }
        mid = start+(end-start)/2;
    }
    return start;
}
int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        int np;
        int nc;
        cin>>np; 
        cin>>nc;
        vector<int>cooksrank;
        while(nc--){
            int rank;
            cin>>rank;
            cooksrank.push_back(rank);
            

        }
        int n = maxtimetaken(cooksrank,np);
        cout<<n<<endl;

    }
   


}