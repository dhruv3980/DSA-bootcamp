#include<iostream>
#include<vector>
using namespace std;

class Heap{
    vector<int>v;


    void heapify( int currentidx){
        if(v.size()<=0){
            return;
        }

        int leftchild=-1;
        int rightchild=-1;
        int maxidx = currentidx;

        if(2*currentidx+1<v.size()){
            leftchild=2*currentidx+1;

        }

        if(2*currentidx+2<v.size()){
            rightchild = 2* currentidx+2;

        }

        if(leftchild!=-1 &&  v[leftchild]>v[maxidx]){
            maxidx=leftchild;
        }

        if(rightchild!=-1 &&  v[rightchild]>v[maxidx]){
            maxidx=rightchild;
        }

        if(currentidx!=maxidx){

            swap(v[currentidx], v[maxidx]);

            heapify(maxidx);

        }



        return;

        


    }

    public:

    void push(int data){
        // fist push at the back of the array;

        // then build heapify if anything wrong

        v.push_back(data);

        int idx = v.size()-1;
        while(idx>0 && v[idx]>v[(idx-1)/2] ){
            swap(v[idx], v[(idx-1)/2]);

            idx = (idx-1)/2;

        }



    }

    void pop(){
        // three steps
        // first swap first elemetn of the array with the last element
        //delete the last element
        // third make heapify

        int lastemelent = v.size()-1;

        swap(v[0], v[lastemelent]);

        v.pop_back();

        heapify(0);

    };

    int top(){
       return v.size()==0?-1:  v[0];
    }

    bool empty(){
        return v.size()==0;
    }

};
int main(){


    Heap h;

    h.push(1);
    h.push(6);
    h.push(3);
    h.push(4);


    while(!h.empty()){
        cout<<"Top"<<h.top()<<endl;

        h.pop();

    }

}