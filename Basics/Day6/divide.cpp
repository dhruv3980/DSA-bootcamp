#include<iostream>
using namespace std;
int divide(int divident, int divisor){
    int start =0;
    int end = abs(divident);
    int mid = start+(end-start)/2;
    int ans=0;
    while(start<=end){
        if(abs(mid*divisor)==abs(divident)){
            ans=mid;
            break;
        }
        if(abs(mid*divisor)<abs(divident)){
            ans = mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
        mid= start+(end-start)/2;
    }
    if((divident >0  && divisor>0)||(divident<0 && divisor<0) ){

        return ans;
    }
    else{
        return -ans;

    }
}
int main(){
    int divident,divisor;
    cout<<"enter  divident ";
    cin>>divident;
    cout<<"Enter divisor ";
    cin>>divisor;
    
    int ans = divide(divident,divisor);
    cout<<ans;
    double finalans=ans;
    double precision =5;
    double step = 0.1;
    for(int i=0; i<precision; i++ ){
        for(double j=finalans; j*divisor<=divident; j=j+step){
            finalans=j;

        }
        step = step/10;

    }
    cout<<endl<<finalans;
}