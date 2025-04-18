#include<iostream>
#include<vector>
using namespace std;
void print (vector<int>&v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void bubblesort(vector<int>&v){
    int size = v.size();
    bool flag = false;
    int swapcount=0;
    for(int i=0 ; i<size-1; i++){
        for(int j=0 ; j<size-1-i; j++){
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
                swapcount++;
            }
        }
        if(swapcount==0){
            break;
        }
    }
}
int main(){
    vector<int>v{5,4,3,2,1};
    cout<<"Before Swapping "<<endl;
    print(v);
    bubblesort(v);
    cout<<" after Swapping "<<endl;
    print(v);
}