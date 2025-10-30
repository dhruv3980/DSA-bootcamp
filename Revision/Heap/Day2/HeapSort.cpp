#include<iostream>
#include<queue>
using namespace std;


void heapify(vector<int>&p, int i, int size){
    // 
    if(size<=0) return;
    int leftchild = 2*i+1;
    int rightchild = 2*i+2;

    int maxidx = i;

    if(leftchild<size  && p[leftchild]>p[maxidx]){
        maxidx = leftchild;

    }

    if(rightchild<size && p[rightchild]>p[maxidx]){
        maxidx = rightchild;
    }

    if(maxidx!= i){
        swap(p[maxidx], p[i]);

        heapify(p, maxidx, size);
    }


}

void HeapSort(vector<int>& p){
    // first step make  heapify the array
    for (int i = p.size()/2 - 1; i >= 0; i--) {
       heapify(p, i, p.size());
    }

    

    // now second we run loop to n/2 to n
    for(int i=p.size()-1; i>=0; i--){
        swap(p[0], p[i]);
        heapify(p, 0, i);
    }



}


int main(){
    vector<int>p;
    p.push_back(1);
    p.push_back(4);
    p.push_back(2);
    p.push_back(5);
    p.push_back(3);

    HeapSort(p);

    for(auto it:p){
        cout<<it<<" ";
    }


}