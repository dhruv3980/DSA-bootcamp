#include<iostream>
#include<vector>
using namespace std;

void printSudoko(int sudoku[][9]){
    for(int i=0; i<9; i++){
        for(int k=0; k<9; k++){
            cout<<sudoku[i][k]<<" ";
        }
        cout<<endl;
    }
}


bool issafe(int sudoku[][9], int row, int col, int digit){

    // check for the vertical 
    for(int i=0; i<9; i++){
        if(sudoku[i][col]==digit){
            return false;
        }
    }

    // check for horizontal

    for(int i=0; i<9; i++){
        if(sudoku[row][i]==digit){
            return false;
        }
    }

    // now check in the grid;
     row = (row/3)*3;
     col = (col/3)*3;

    for(int i=row; i<row+3; i++){
        for(int k=col; k<col+3; k++){
            if(sudoku[i][k]==digit){
                return false;
            }
        }
    }

    return true;

}


bool sudokuSolver(int sudoku[][9], int row, int col){

    if(row==9){

        printSudoko(sudoku);

        return true;
    }

    int nextrow = row;
    int nextcol = col+1;
    if(nextcol==9){
        nextrow=row+1;
        nextcol=0;
    }

    if(sudoku[row][col]!=0){
        return sudokuSolver(sudoku,nextrow, nextcol);
    }

    for(int i=1; i<=9; i++){
       
        if(issafe(sudoku, row, col, i)){
            sudoku[row][col]=i;

            if(sudokuSolver(sudoku, nextrow, nextcol)){
                return true;
            }
            sudoku[row][col]=0;

        }

        
    }

    return false;

}
int main(){

    int sudoku[9][9]={{0,0,8,0,0,0,0,0,0},
                      {4,9,0,1,5,7,0,0,2},
                      {0,0,3,0,0,4,1,9,0},
                      {1,8,5,0,6,0,0,2,0},
                      {0,0,0,0,2,0,0,6,0},
                      {9,6,0,4,0,5,3,0,0},
                      {0,3,0,0,7,2,0,0,4},
                      {0,4,9,0,3,0,0,5,7},
                      {8,2,7,0,0,9,0,1,3}

                     };


    

    bool ans = sudokuSolver(sudoku, 0,0);

    cout<<endl;



}