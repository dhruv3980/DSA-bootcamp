#include<iostream>
#include<vector>
using namespace std;
void wave (vector<vector<int> >  v){
    int rows=v.size();
    int cols=v[0].size();
    for(int i=0; i<cols; i++){
       if(i%2 ==0){
        for(int j=0 ; j<rows; j++){
            cout<<v[j][i]<<" ";
        }
        cout<<endl;
       }
       else{
        for(int j=rows-1; j>=0; j--){
            cout<<v[j][i]<<" ";
        }
        cout<<endl;
       }
    }

}
int main(){
    vector<vector<int> > arr =
    {
        {1,2,3,4,5},
        {4,5,6,7,8},
        {9,10,11,12,13}
    };
    wave(arr);

}