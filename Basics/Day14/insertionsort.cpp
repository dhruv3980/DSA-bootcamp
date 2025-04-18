#include<iostream>
#include<vector>
using namespace std;
void print (vector<int>&a){
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void insertionsort(vector<int>&a){
    int n=a.size();
    for(int i=1; i<n; i++){
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;

        }
        a[j+1]=key;
    }
}
int main(){
    vector<int>a{5,4,3,2,5};
    insertionsort(a);
    print(a);

}