#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int>&a, int start, int end){
    int pivotelement = a[end];
    int idx =start-1;
    
    for(int j=start; j<end; j++){
        if(a[j]<=pivotelement){
            swap(a[++idx], a[j]);

        }
    }

    idx++;
    swap(a[idx], a[end]);

    return idx;

}
void quickSort(vector<int>&a , int start, int end){
    if(start<end){
        int pivot = partition(a, start, end);

        quickSort(a, start, pivot-1);
        quickSort(a, pivot+1, end);
    }
}
int main(){
    vector<int>a{5,4,1,6,18,4,6,4};

    quickSort(a, 0, a.size()-1);

    for(int ele:a){
        cout<<ele<<" ";
    }

}