#include<iostream>
#include<vector>
using namespace std;
void print (vector<int>&v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

}
void selectionsort(vector<int>&v){
    int n =v.size();
    for(int i=0; i<n; i++){
        int miniidx=i;
        for(int j=i+1; j<n; j++){
            if(v[j]<v[miniidx]){
                miniidx=j;
            }
        }
        swap(v[miniidx],v[i]);
    }

}
int main(){
    vector<int>v{44,33,55,22,11};
    cout<<"Before swapping"<<endl;
    print(v);
    selectionsort(v);
    cout<<"After Swapping "<<endl;
    print(v);
}