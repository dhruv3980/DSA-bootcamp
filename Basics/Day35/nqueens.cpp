#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

unordered_map<int,bool>rowcheck;
unordered_map<int, bool>upperLeftDiagonalCheck;
unordered_map<int,bool>bottomLeftDiagonalCheck;
void printqueen(vector<vector<char> >&board, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"next sol"<<endl;
}
bool issafe(vector<vector<char> >&board, int n, int row, int col){
    if(rowcheck[row]==true){
        return false;
    }

    if(upperLeftDiagonalCheck[n-1+col-row]==true){
        return false;
    }
    if(bottomLeftDiagonalCheck[row+col]==true){
        return false;
    
    }
    return true;










    // int i=row;
    // int j=col;
    // // left

    // while(j>=0){
    //     if(board[i][j]=='Q'){
    //         return false;
    //     }
    //     j--;
    // }

    // // Upper Diagonal
    // j=col;

    // while(i>=0 && j>=0){
    //     if(board[i][j]=='Q'){
    //         return false;
    //     }
    //     i--;
    //     j--;

    // }

    // // down diagonal
    // i=row;
    // j=col;

    // while(i<n && j>=0){
    //     if(board[i][j]=='Q'){
    //         return false;
    //     }
    //     i++;
    //     j--;
    // }
    
    // return true;

   

}
void nqueen(vector<vector<char> >& board, int n, int col ){
    if(col>=n){ // Base Case
        printqueen(board,n);
        return;
    }

    for(int row =0; row<n; row++){
        if(issafe(board, n,row,col)){
            board[row][col]='Q';
            rowcheck[row]=true;
            upperLeftDiagonalCheck[n-1+col-row]=true;
            bottomLeftDiagonalCheck[row+col]=true;



            //recursion sol lagega
            nqueen(board, n,col+1);
            board[row][col]='-';
            rowcheck[row]=false;
            upperLeftDiagonalCheck[n-1+col-row]=false;
            bottomLeftDiagonalCheck[row+col]=false;

        }
    }


}
int main(){
    int n=4;
    vector<vector<char> >board (n,vector<char>(n,'-'));

    nqueen(board, n,0);

}