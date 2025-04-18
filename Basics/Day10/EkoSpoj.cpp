#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool ispossiblesol(vector<long long int> trees, long long int bladeheight, long long int sol){
    long long int woodcount =0;
    long long int size = trees.size();
    for(long long int i=0; i<size; i++){
        if(trees[i]>sol){
            woodcount+=trees[i]-sol;
        }
    }
    if(woodcount>=bladeheight){
        return true;
    }
    else{
        return false;
    }
}
long long int sawbladeheight(vector<long long int> trees, long long int bladeheight){
    long long int start=0;
    long long int end = *max_element(trees.begin(), trees.end());
    long long int mid = start+(end-start)/2;
    while(start<=end){
        if(ispossiblesol(trees, bladeheight,mid)){
            start=mid+1;
        }
        else{
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }
    return end;

}

int main(){
    long long int m,n;
    cout<<"enter the saw blade height";
    cin>>m;
    cout<<"enter the no of trees";
    cin>>n;

    vector<long long int>trees; // enter the trees height
    for(long long int i=0; i<n; i++){
        long long el;
        cin>>el;
        trees.push_back(el);

    }
    cout<<sawbladeheight(trees,m);
    return 0;


}