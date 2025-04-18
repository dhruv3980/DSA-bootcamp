#include<iostream>
#include<vector>
using namespace std;
// it can find unique element when all the element of vector is exactly appear twice and only one element dont repeat then it will give the answer
int find(vector<int>arr){
    int ans=0;
    for(int i=0; i<arr.size(); i++){
        ans=ans^arr[i];
    }
    return ans;
}
int main(){
    cout<<"Enter the size of an array";
    int n;
    cin>>n;
    vector<int>arr(n);
    cout<<"Enter the array element"<<endl;
    for(int i=0; i<n ; i++){
        cin>>arr[i];
    }
    int uniqueelement = find(arr);
    cout<<"Unique element is "<<uniqueelement<<" ";

}