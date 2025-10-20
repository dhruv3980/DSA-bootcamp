#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int maxAreaInHistogram(vector<int>heights){
     int n = heights.size();
    vector<int>psl(n);
    vector<int>nsr(n);

    stack<int> s;
   
    psl[0]=-1;
    s.push(0);

    for(int i=1; i<n; i++ ){
        while(!s.empty() && heights[s.top()]>=heights[i]){
            s.pop();
        }

        if(s.empty()){
            psl[i]=-1;
        }
        else{
            psl[i]=s.top();
        }

        s.push(i);
    }

   
    while(!s.empty()){
        s.pop();
    }

    nsr[n-1]=n;
    s.push(n-1);

    for(int i=n-2; i>=0; i--){
        while(!s.empty() && heights[s.top()]>=heights[i]){
            s.pop();
        }

        if(s.empty()){
            nsr[i]=n;
        }else{
            nsr[i]=s.top();
        }

        s.push(i);
    }

   
    int maxarea = 0;

    for(int i=0; i<n; i++){
        int height = heights[i];

        int width = nsr[i]-psl[i]-1;

        int area = height* width;

       

        maxarea=max(area, maxarea);

    }



    return maxarea;

}
int main(){
    vector<int> heights = {2,1,5,6,2,3};
    int ans=maxAreaInHistogram(heights);
    cout<<"maxarea is "<<ans;
}