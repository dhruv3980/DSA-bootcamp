#include<iostream>
#include<vector>
using namespace std;
int find(vector<int>a){
    int start=0;
    int end = a.size()-1;
    int mid = start+(end-start)/2;
    while(start<=end){
        if(start==end){
            return start;
        }
        if(mid%2==0){ // we stand out on even index
            if(a[mid]==a[mid+1]){ // that means we satnd out on left side of the answe
                start = mid+2;
            }
            else{  // it can be answer and we search on the left part
                end=mid;
            }
        }
        else{ // we stand out on odd index 
            if(a[mid]==a[mid-1]){   // we standout on left part
                start = mid+1;
            }
            else{  // we satnd out on the right  it can not be answer because negative idx never be a ans
                end=mid-1;
            }


            
        }
        mid = start+(end-start)/2;
    }
    return -1;
}
int main(){
    vector<int> a{1,1,2,2,3,3,4,4,3,600,600,4,4};
    int idx = find(a);
    cout<<"answer is "<<a[idx];
}