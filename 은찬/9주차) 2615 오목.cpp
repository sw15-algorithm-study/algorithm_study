#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board(25, vector<int>(25, 0));

int rowCheck(int i, int j){
    int current = board[i][j];

    for(int k = 1; k <= 4; k++){
        if(board[i][j + k] != current){
            return -1;
        }
    }

    //6목 이상이면 -1 리턴
    //5목이면 1 리턴
    if(board[i][j - 1] == current || board[i][j + 5] == current){
        return -1;
    }
    else{
        return 1;
    }
}

int colCheck(int i, int j){
    int current = board[i][j];

    for(int k = 1; k <= 4; k++){
        if(board[i + k][j] != current){
            return -1;
        }
    }

    //6목 이상이면 -1 리턴
    //5목이면 1 리턴
    if(board[i - 1][j] == current || board[i + 5][j] == current){
        return -1;
    }
    else{
        return 1;
    }
}

int rdDiagonalCheck(int i, int j){
    int current = board[i][j];

    for(int k = 1; k <= 4; k++){
        if(board[i + k][j + k] != current){
            return -1;
        }
    }

    //6목 이상이면 -1 리턴
    //5목이면 1 리턴
    if(board[i - 1][j - 1] == current || board[i + 5][j + 5] == current){
        return -1;
    }
    else{
        return 1;
    }
}

int ruDiagonalCheck(int i, int j){
    int current = board[i][j];

    for(int k = 1; k <= 4; k++){
        if(board[i - k][j + k] != current){
            return -1;
        }
    }

    //6목 이상이면 -1 리턴
    //5목이면 1 리턴
    if(board[i + 1][j - 1] == current || board[i - 5][j + 5] == current){
        return -1;
    }
    else{
        return 1;
    }
}

int main(void){
    for(int i = 1; i < 20; i++){
        for(int j = 1; j < 20; j++){
            cin >> board[i][j];
        }
    }

    //play
    for(int i = 1; i < 20; i++){
        for(int j = 1; j < 20; j++){
            if(board[i][j] == 0){
                continue;
            }
            
            if(rowCheck(i, j) == 1){
                cout << board[i][j] << "\n" << i << " " << j;
                return 0;
            }
            else if(colCheck(i, j) == 1){
                cout << board[i][j] << "\n" << i << " " << j;
                return 0;
            }
            else if(rdDiagonalCheck(i, j) == 1){
                cout << board[i][j] << "\n" << i << " " << j;
                return 0;
            }
            else if(ruDiagonalCheck(i, j) == 1){
                cout << board[i][j] << "\n" << i << " " << j;
                return 0;
            }
        }
    }

    cout << 0;
    return 0;
}