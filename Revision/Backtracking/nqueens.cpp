#include<iostream>
#include<vector>
using namespace std;

void printBoard(vector<vector<char>>board){
    int size = board.size();

    for(int i=0; i<size; i++){
        for(int k=0; k<size; k++){
            cout<<board[i][k]<<" ";
        }

        cout<<endl;
    }

    cout<<"-------------------------------"<<endl;


}

bool isSafe(vector<vector<char>>board, int row, int col){
    // for horizontal check
    int n=board.size();

    for(int i=0; i<n; i++){
        if(board[row][i]=='Q'){
            return false;
        }
    }

    // now check for vertical whether the placing queen is safe or not
    for(int j=0; j<n; j++ ){
        if(board[j][col]=='Q'){
            return false;
        }
    }

    // now here for first diagonal check

    for(int i=row, j=col ; i>=0 && j>=0; i--, j--){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    // for second diagonal
    for(int i=row, j=col; i>=0 && j<n; i--, j++){
        if(board[i][j]=='Q'){
            return false;
        }
    }

    // here all the place check that means the place is safe so i place here the queen so return true;

    return true;
}


int  nQueens(vector<vector<char>>board, int row){
    int n=board.size();

    if(row==n){
        printBoard(board);
        return 1;
       
    }


    int count =0;
    for(int j=0; j<n; j++){
        if(isSafe(board, row, j)){
     
             
            board[row][j]='Q';
            count+=nQueens(board, row+1);

            board[row][j]='*';
        }


    }

    return count;

}
int main(){
    vector<vector<char>>board;
    int n=5;


    for(int i=0; i<n; i++){
        vector<char>row;
        for(int j=0; j<n; j++){
            row.push_back('*');
        }
        board.push_back(row);
    }

    int ans=nQueens(board, 0);

    cout<<endl<<ans;


}