#include<iostream>
#include<vector>
using namespace std;
int firstoccur(vector<int>v,int target){
    int i=0;
    int j=v.size()-1;
    int mid = i+(j-1)/2;
    int ans=-1;
    while(i<=j){
        if(v[mid]==target){
            ans=mid;
            j=mid-1;
        }
        else if(v[mid]<target){
            i=mid+1;
        }
        else{
            j=mid-1;
        }
        mid = i+(j-i)/2;
    }
    return ans;
}
int lastoccur(vector<int>v,int target){
    int i=0;
    int j=v.size()-1;
    int mid = i+(j-1)/2;
    int ans=-1;
    while(i<=j){
        if(v[mid]==target){
            ans=mid;
            i=mid+1;
        }
        else if(v[mid]<target){
            i=mid+1;
        }
        else{
            j=mid-1;
        }
        mid = i+(j-i)/2;
    }
    return ans;
}
int main(){
    vector<int>v{1,2,3,4,4,4,4,4,5,6,7};
    int target=4;
    int ans1=firstoccur(v,target);
    int ans2=lastoccur(v,target);
    int totaloccur = ans2-ans1+1;
    cout<<totaloccur;

}