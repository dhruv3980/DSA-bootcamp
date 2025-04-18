#include<iostream>
#include<vector>
using namespace std;
int find(vector<int>v, int target){
    int start= 0;
    int end = v.size()-1;
    int mid = start+(end-start)/2;
    // if(v.size()<=1){   // we can handle edge case with the help of this case 
    //     if(v[0]==target){
    //         return 0;
    //     }
    //     else{
    //         return -1;
    //     }
    // }
    while(start<=end){
        if( v[mid]==target){
            return mid;
        }
        if(mid-1>=0 && v[mid-1]==target){
            return mid-1;

        }
        if(mid+1<v.size() && v[mid+1]==target){
            return mid+1;
        }
        if(v[mid]<target){
            start=mid+2;

        }
        else{
            end=mid-2;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}
int main(){
    vector<int> a{10,3,40,20,50,80,70};
    int target =20;
    int n = find(a,target);
    cout<<target<<" is found at the index"<<" "<<n;

}