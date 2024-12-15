#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



// 全排列
void track_back(vector<int>& nums, vector<int>& path, vector<vector<int>>& res, vector<int>& used){
    // 结束条件判断
    if(nums.size() == path.size()){
        res.push_back(path);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        /* code */
        if (used[i] == 1) continue;

        path.push_back(nums[i]);
        used[i] = 1;
        track_back(nums, path, res, used);
        
        path.pop_back();
        used[i] = -1;
    }    
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());
    // int max = nums[nums.size() - 1];
    vector<int> used(nums.size(), -1);
    vector<int> path;

    track_back(nums, path, res, used);

    return res;    
}

// N皇后问题
bool IsValidNqueue(int n, vector<string>& sigleNqueue, int row, int col){

    // row
    for (int i = 0; i < n; i++)
    {
        if (sigleNqueue[row][i] == 'Q') return false;
    }
    // col
    for (int i = 0; i < n; i++)
    {
        if (sigleNqueue[i][col] == 'Q') return false;
    }
    // left angle
    int size = min(row, col) + 1;
    for (int i = 0; i < size; i++)
    {
        if (sigleNqueue[row-i][col-i] == 'Q') return false;
    }    

    // right angle
    int size1 = min(row, (n-col-1)) + 1;
    for (int i = 0; i < size1; i++)
    {
        if (sigleNqueue[row-i][col+i] == 'Q') return false;
    } 

    return true;
}

void Nquene(vector<vector<string>>& res, int n, vector<string>& sigleNqueue, int row, int q_cnt){
    //1.Judgment end condition
    // if ((row+1) != q_cnt) return;


    if ((n == (row+1))) {
        res.push_back(sigleNqueue);
        return;
    } 

    // if ((n == (row+1)) && (q_cnt != n)) {
    //     return;
    // }

    //2. 选择条件循环
    for (int i = (row+1); i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {   

            //3. 条件判断
            bool is_valid = IsValidNqueue(n, sigleNqueue, i, j);

            if ((is_valid == false) && (j != (n-1)) ) {
                continue;
            } else if ((is_valid == false) && (j == (n-1))) {
                return ;
            } else {
                // pass
            }

            sigleNqueue[i][j] = 'Q'; 
            for (int s = 0; s < n; s++)
            {
                cout << sigleNqueue[s] << endl; 
            }
             
            cout << endl;
            cout << endl;
            q_cnt++;  
            //4. 递归执行
            Nquene(res, n, sigleNqueue, i, q_cnt);

            //5. 条件撤销
            sigleNqueue[i][j] = '.';  
            q_cnt--;
        }

        if ((i + 1) != q_cnt) break;
        
    }

    
}


vector<vector<string>> solveNQueens(int n) {

    // vector<vector<string>> res(n, (vector<string>(n, ' . ')));
    string m(n, '.');
    vector<string> sigleNqueue(n, (string)m);
    vector<vector<string>> res;

    Nquene(res, n, sigleNqueue, -1, 0);


    return res;   
}

// N皇后II : 计算N皇后个数
bool IsValidNqueue(int n, vector<string>& sigleNqueue, int row, int col){

    // row
    for (int i = 0; i < n; i++)
    {
        if (sigleNqueue[row][i] == 'Q') return false;
    }
    // col
    for (int i = 0; i < n; i++)
    {
        if (sigleNqueue[i][col] == 'Q') return false;
    }
    // left angle
    int size = min(row, col) + 1;
    for (int i = 0; i < size; i++)
    {
        if (sigleNqueue[row-i][col-i] == 'Q') return false;
    }    

    // right angle
    int size1 = min(row, (n-col-1)) + 1;
    for (int i = 0; i < size1; i++)
    {
        if (sigleNqueue[row-i][col+i] == 'Q') return false;
    } 

    return true;
}

void Nquene(int& res, int n, vector<string>& sigleNqueue, int row, int q_cnt){
    //1.Judgment end condition
    // if ((row+1) != q_cnt) return;


    if ((n == (row+1))) {
        res++;
        return;
    } 

    // if ((n == (row+1)) && (q_cnt != n)) {
    //     return;
    // }

    //2. 选择条件循环
    for (int i = (row+1); i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {   

            //3. 条件判断
            bool is_valid = IsValidNqueue(n, sigleNqueue, i, j);

            if ((is_valid == false) && (j != (n-1)) ) {
                continue;
            } else if ((is_valid == false) && (j == (n-1))) {
                return ;
            } else {
                // pass
            }

            sigleNqueue[i][j] = 'Q'; 
            // for (int s = 0; s < n; s++)
            // {
            //     cout << sigleNqueue[s] << endl; 
            // }
             
            // cout << endl;
            // cout << endl;
            q_cnt++;  
            //4. 递归执行
            Nquene(res, n, sigleNqueue, i, q_cnt);

            //5. 条件撤销
            sigleNqueue[i][j] = '.';  
            q_cnt--;
        }

        if ((i + 1) != q_cnt) break;
        
    }

    
}


int totalNQueens(int n) {

    // vector<vector<string>> res(n, (vector<string>(n, ' . ')));
    string m(n, '.');
    vector<string> sigleNqueue(n, (string)m);

    int res = 0;
    Nquene(res, n, sigleNqueue, -1, 0);


    return res;   
}


//解数独

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

void solveSudoku(vector<vector<char>>& board) {
    
    (void)solveSudoku_backTrack(board, 0, 0);
}