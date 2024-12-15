#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


bool isValid(vector<vector<char>>& board, int row, int col, char value){
    // condtion 1
    for (int i = 0; i < 9; i++)
    {
        if(board[row][i] == value) {return false;}
    }
    // condtion 2
    for (int i = 0; i < 9; i++)
    {
        if(board[i][col] == value) {return false;}
    }    
    // condition 3
    int r1, l1;
    r1 = row/3;
    l1 = col/3;
    for (int m = 3*r1; m < (3*r1+3); m++)
    {
        for (int n = 3*l1; n < (3*l1+3); n++)
        {
            if(board[m][n] == value) {
                return false;
            }
        }
        
    }

    return true;
    
}

// char getValidValue(vector<vector<char>>& board, int row, int col){

//     for (int i = 0; i < 9; i++)
//     {
//         char value = to_string(i+1)[0];
//         if (isValid(board, row, col, value)){
//             return value;
//         }
//     }


//     return 'x';
// }

bool solveSudoku_backTrack(vector<vector<char>>& board, int row, int col){
    if(row == 9){
        return false;
    } // base line

    // 选择条件
    for (int i = row; i < 9; i++)
    {
        for (int j = col; j < 9; j++)
        {   
                // if (i == 1) {
                //     cout << "aa";
                // };

                if (board[i][j] == '.'){
                    
                    for (char k = '1'; k <= '9'; k++)
                    {
                        // 择优
                        if (!isValid(board, i, j, k)) continue;
                        board[i][j] = k;
                
                        // 递归
                        bool res;
                        if(j < 8) {
                            res = solveSudoku_backTrack(board, i, j+1);
                        } else {
                            res = solveSudoku_backTrack(board, i+1, 0);
                        }

                        // if(row == 8 && col == 8)
                        // base line
                        if (res) {
                            return true;
                        }
                        if ((i == 8) && (j == 8) && (board[i][j] != '.')) {
                            return true;
                        }


                        // 撤销选择
                        board[i][j] = '.';                     
                    }

                    return false; 
                }
    
                // base line
                if (i == 8 && j == 8) {
                    return true;
                } else if (i != 8 && j == 8) {
                    col = 0;
                }

        }

    }

    return false; 
}


// 解数独
void solveSudoku(vector<vector<char>>& board) {
    
    (void)solveSudoku_backTrack(board, 0, 0);
}

int main(){

    // bool ret = isPalindrome(123);
    // cout << ret << endl;
    // Solution s;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    vector<int> nums3 = {3,2,3};

    vector<char> mm = {'b'};
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}};

    // bool ret = isValid(board, 0, 2, '9'); 
    // char c = getValidValue(board, 0, 2);
    // cout << c << endl;

    solveSudoku(board);

    cout << "run over" << endl;
    return 0;
}

