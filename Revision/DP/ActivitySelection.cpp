#include<iostream>
#include<vector>
using namespace std;

int ActivitySelectionProblem(vector<int>start, vector<int>end){
    int ans = 1;

    int safe = end[0];

    for(int i=1; i<start.size(); i++){
        if(start[i]>=safe){
            
            ans++;
            safe = end[i];
        }

    }
    return ans;
}
int main(){
    vector<int>start={10,12,20};
    vector<int>end = {20,25,30};

    cout<<ActivitySelectionProblem(start, end);

}