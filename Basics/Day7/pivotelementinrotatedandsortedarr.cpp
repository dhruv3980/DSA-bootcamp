#include<iostream>
#include<vector>
using namespace std;
int  findpivot(vector<int>v){
    int start =0;
    int end =v.size()-1;
    int mid = start+(end-start)/2;
    while(start<=end){
        if(start==end){
            return start;
        }
        if( mid+1<=end && v[mid]>v[mid+1]){
            return mid;
        }
        else if (mid-1>=0 && v[mid]<v[mid-1]){
            return mid-1;
        }

        if(v[mid]>v[start]){ // right search
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}
int main(){
    vector<int>a{9,10,2,4,6,8};
    int ans = findpivot(a);
    if(ans==-1){
        cout<<"kuch to gadbad ha";
    }
    else{
        cout<<"element at index"<<ans<<endl;
        cout<<"element is "<<a[ans];
    }
} 