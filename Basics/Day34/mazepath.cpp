#include<iostream>
#include<vector>
using namespace std;
bool issafe(vector<vector<int>> &arr, vector<vector<bool> > &visited, int i, int j, int row, int col){
    if((i>=0 && i<row) && (j>=0 && j<col)  && (arr[i][j]==1) && (visited[i][j]==false)){
        return true;
    }
    else{
        return false;
    }
}
void mazepath(vector<vector<int> > &arr, vector<vector<bool> > &visited, int i, int j, int row, int col, vector<string>& path, string output){
    if(i==row-1 && j==col-1){
        path.push_back(output);
        return ;


    }
    // down
    if(issafe(arr, visited,i+1,j, row,col)){
        visited[i+1][j]=true;
        mazepath(arr,visited,i+1,j,row,col,path, output+'D');
        visited[i+1][j]=false;
    }

    
    // lrft
    if(issafe(arr, visited,i,j-1, row,col)){
        visited[i][j-1]=true;
        mazepath(arr,visited,i,j-1,row,col,path, output+'L');
        visited[i][j-1]=false;
    }
    
    // right
    if(issafe(arr, visited,i,j+1, row,col)){
        visited[i][j+1]=true;
        mazepath(arr,visited,i,j+1,row,col,path, output+'R');
        visited[i][j+1]=false;
    }
    // up
    if(issafe(arr, visited,i-1,j, row,col)){
        visited[i-1][j]=true;
        mazepath(arr,visited,i-1,j,row,col,path, output+'U');
        visited[i-1][j]=false;
    }

    // down
   

}
int main(){
    string output="";
    vector<vector<int> > arr{{1,0,0,0},{1, 1, 0, 1},{1, 1, 0, 0},{0, 1, 1, 1}};
    int rows =4;
    int cols=4;

    if(arr[0][0]==0){
        return 0;
    }

  
    vector<string>path;
    vector<vector<bool> > visited(rows, vector<bool>(cols, false));

    visited[0][0] = true;

    mazepath(arr,visited,0,0,rows,cols,path,output);

    for(auto i:path){
        cout<<i<<" ";
    }




}