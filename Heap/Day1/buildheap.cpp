#include <iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int>arr;
    public:

    void heapify(int idx){
        // if(idx>=arr.size()){
        //     return;
        // }

        int l = 2*idx+1;
        int r = 2*idx+2;
        int maxidx = idx;

        if(l<arr.size() && arr[l]>arr[maxidx]){
            maxidx =l;

        }
        if(r<arr.size() && arr[r]>arr[maxidx]){
            maxidx = r;
        }

        swap(arr[maxidx],  arr[idx]);

        if(maxidx!=idx){

            heapify(maxidx);
        }

    }

    void push(int data){
        arr.push_back(data);

        int x = arr.size()-1;
        // there will be two scenerio if x is root then its left child array index is 2*i+1 and right child index value is 2*i+2

        int pidx = (x-1)/2;

        while(pidx>=0 && arr[pidx]<arr[x]){ // if to make min heap just reverse the condition if(arr[pidx]> arr[x]) then swap
            swap(arr[pidx], arr[x]);
            x=pidx;
            pidx = (x-1)/2;
        }




    }
    void pop(){
        // step 1 reverse the arr[0] to the last index of the array
        //step 2 delete the last element of the array
        //step 3 make heapify

        swap(arr[0], arr[arr.size()-1]);

        arr.pop_back();

        heapify(0);

    }

    int top() {
        if(isEmpty()){
            return 0;
        }
        return arr[0];
    }


    bool isEmpty(){
        return arr.size()==0;

    }


};

int main(){

    Heap a;

    a.push(5);
    a.push(10);
    a.push(11);
    
    while(!a.isEmpty()){
        cout<<a.top()<<" ";

        a.pop();

    }
    


    
}