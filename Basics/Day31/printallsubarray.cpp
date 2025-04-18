#include<iostream>
#include<vector>
using namespace std;
void printsubarray(vector<int>& nums , int start, int end){
    // base case
    
    if(end==nums.size()){
        return;
    }

    for(int i =start; i<=end; i++){
        cout<<nums[i]<<" ";
    }
   cout<<endl;

    printsubarray(nums, start, end+1);


}
void printallsubarray(vector<int>& nums){
    for(int i=0; i<nums.size(); i++){
        printsubarray(nums, i, i);
    }
}
int main(){
    vector<int>nums{1,2,3,4,5};
    printallsubarray(nums);
}