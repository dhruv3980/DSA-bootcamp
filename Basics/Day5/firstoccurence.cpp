#include<iostream>
#include<vector>
using namespace std;
int firstoccur(vector<int>v, int target){
    int start=0;
    int end = v.size()-1;
    int ans=-1;
    int mid=start+(end-start)/2;
    while(start<=end){
        if(v[mid]==target){
            ans=mid;
            end=mid-1;

        }
        else if(v[mid]<target){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return ans;

}
int main(){
    vector<int>v{1,2,2,2,3,4,4,4,4,5,6,7};
    int target=4;
    int idx = firstoccur(v,target);
    cout<<"element at idx "<<idx;
}

