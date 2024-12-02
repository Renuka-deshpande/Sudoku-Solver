#include <iostream>
#include <vector>
#define N 9
using namespace std;

void printBoard(const vector<vector<int> >& board)
{
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++){
            cout << board[r][d] << " ";
        }
        cout << endl;
    }
}

bool isSafe(const vector<vector<int> >& board, int row,int col, int num)
{
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num) {
            return false;
        }
    }

    for (int x = 0; x < N; x++) {
        if (board[x][col] == num) {
            return false;
        }
    }

int startRow = row - row % 3;
int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudokuBacktracking(vector<vector<int> >& board)
{
    int row = -1;
    int col = -1;
    bool isEmpty = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    if (isEmpty) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;
            if (solveSudokuBacktracking(board)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    cout<<"-----Welcome to the Sudoku Solver-----"<<endl;
    vector<vector<int>> board(N,vector<int>(N,0));
    cout<<"Enter the sudoku grid(for blank space enter 0)"<<endl;
    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++){
            cin>>board[row][col];
        }
    }

    if (solveSudokuBacktracking(board)) {
        cout<<endl;
        cout<<"Your solved sudoku is"<<endl;
        printBoard(board);
    }else{
        cout<<"No solution exists"<<endl;
    }
    return 0;
}