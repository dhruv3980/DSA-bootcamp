#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int find(int tar){
                                           // Method 1
    // vector<int>a(tar+1);
    // for(int i=0 ; i<a.size(); i++){
    //     a[i]=i;
    // }
    // for( int b:a){
    //     cout<<b<<" ";
    // }
    // int start=0;
    // int end=a.size()-1;
    // int mid=start+(end-start)/2;
    // int ans =-1;

    // while (start<=end){
    //     int element =a[mid];
    //     if(element*element==tar){
    //         return element;
    //     }
    //     else if(element*element<tar){
    //         ans = element;
    //         start=mid+1;

    //     }
    //     else {
    //         end = mid-1;
    //     }
    //     mid = start+(end-start)/2;
    // }
    // return ans;

    //methid 2
    int target = tar;
    int start =0 ;
    int end = target;
    int mid = start+(end-start)/2;
    int ans =-1;
    while(start<=end){
        if(mid*mid==target){
            return mid;
        }
        else if(mid*mid<target){
            ans=mid;
            start=mid+1;

        }
        else{
            end=mid-1;
        }
        mid = start+(end-start)/2;
    }
    return ans;

}
int main(){
    int tar=27;
    int precision;
    cin>>precision;
    int sqrt = find(tar);

    cout<<"answer is "<<sqrt;
    double  finalans=sqrt;
    double step =0.1;
    for(int i=0; i<precision; i++){
        for(double j=finalans; j*j<=tar; j=j+step){
            finalans =j;

        }
        step/=10;
    }
    cout<<"finalans is "<<finalans;


}
