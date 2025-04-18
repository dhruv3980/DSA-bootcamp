#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;
// int findmax(int arr[], int length){
//     if(length==0){
//         return arr[0];
//     }
//     return max(arr[length-1],findmax(arr,length-1));
// }
void findmax(int arr[], int n, int i, int &maxi){
    if(i==n){
        return;
    }
    if(arr[i]>maxi){
        maxi=arr[i];
    }
    findmax(arr,n,i+1,maxi);

}
int main(){
    int arr[]={5,14,3,2,1};
    int i=0;
    int max = INT_MIN;
    findmax(arr,5,i,max);
    cout<<max;
    
}