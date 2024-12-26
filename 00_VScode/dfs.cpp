#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1); // dp[i] defination: the LCS of the sub-sorts last element is nums[i];

    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
                dp[i] = max(dp[j]+1, dp[i]);
        }
    }
    
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        res = max(res, dp[i]);
    }


    return res;
    
}

    int fib(int n) {
        if (n == 0 || n == 1) return n;

        return fib(n-1) + fib(n-2);
    }

// 凑零钱
vector<int> mem;
int dp_coinChange(vector<int>& coins, int amount){
        if(amount == 0) return 0;
        if (amount < 0) return -1;

        if (mem[amount] != INT_MAX) return mem[amount];
        
        // int size = coins.size();
        int res = INT_MAX;
        for (int i = 0; i < size; i++)
        {   
            int rst = dp_coinChange(coins, amount - coins[i]);;
            if(rst < 0) continue;
            // if (tmp == -1) return -1;

            res = min(res, rst+1);
            // if (tmp == 0) break;    
        }
        
        //if (res == INT_MAX) return -1;

        if(res == INT_MAX) return res = -1;
        mem[amount] = res;
        return res;
    }


    int coinChange(vector<int>& coins, int amount) {
        mem = vector<int>(amount+1, INT_MAX);
        return dp_coinChange(coins, amount);
    }


// 最小路径和
    void dp_minFallingPathSum(vector<vector<int>>& dp, vector<vector<int>>& matrix, int row){
        if (row == 0) {
            // end condition
            return ;
        }

        
        for (int i = 0; i < matrix.size(); i++)
        {
            dp_minFallingPathSum(dp, matrix, row-1);
            if(i == 0) {
                dp[row][i] =  min(dp[row-1][i], dp[row-1][i+1]) + matrix[row][i]; // 状态转移方程
            } else if(i == (matrix.size()-1)){
                dp[row][i] =  min(dp[row-1][i], dp[row-1][i-1]) + matrix[row][i]; // 状态转移方程
            } else {
                dp[row][i] =  min(dp[row-1][i], min(dp[row-1][i-1], dp[row-1][i+1])) + matrix[row][i]; // 状态转移方程
            }
        }
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Init value
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), 20000));
        // base line
        for (int i = 0; i < matrix.size(); i++)
        {
            dp[0][i] = matrix[0][i];
        }

        dp_minFallingPathSum(dp, matrix, (matrix.size()-1));
        
        int size = matrix.size();
        int res = 20000;
        for(int val : dp[size-1]){
            res = min(res, val);
        }

        return res;
    }


    int minFallingPathSum1(vector<vector<int>>& matrix) {
        /*  
        设dp[i][j] 为 (i, j) 坐标的最小和, 
        那么dp[i][j] = Math.min(dp[i-1][j], dp[i-1][j-1], dp[i-1][j+1]) + matirx[i][j];
        因为dp[i][j] 只能由这3中途径获得, 
        dp[0][j] = matrix[0][j];
        */
        // Init value
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), 20000));
        int size = matrix.size();
        // base line
        for (int i = 0; i < matrix.size(); i++)
        {
            dp[0][i] = matrix[0][i];
        }

        // dp_minFallingPathSum(dp, matrix, (matrix.size()-1));
        for (int i = 1; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                if (j == 0) {
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]) + matrix[i][j];
                } else if (j == (matrix.size() - 1)) {
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + matrix[i][j];
                } else {
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j+1], dp[i-1][j-1])) + matrix[i][j];
                }
            }
        }
        
        int res = 20000;
        for(int val : dp[size-1]){
            res = min(res, val);
        }

        return res;
    }