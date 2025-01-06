#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 未debug
int dp_findCheapestPrice(int n, vector<vector<int>>& flights, int k, vector<int>& dp, int src, int dst, int cnt){
   if(cnt > k) {
        return -1;
   }

    if (dst == src) {
        return 0;
    }

    int size = flights.size();
    int min_cost = INT_MAX;
    int ret;
    for (int i = 0; i < size; i++)
    {
        if(flights[i][1] == dst) {
            ret = dp_findCheapestPrice(n, flights, k, dp, src, flights[i][0], 1);

            min_cost = min(min_cost, (dp[flights[i][0]] + flights[i][2]));
        }
    }
    
    dp[dst] = min_cost;

    return ((dp[dst] == INT_MAX) ? -1 : 0);

}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K){
    // dp数组 ：表示到达每个城市的最小消费
    int size = flights.size();

    vector<int> dp(n, INT_MAX);
    dp[src] = 0;

    dp_findCheapestPrice(n, flights, K, dp, src, dst, 0);

    return dp[dst] == INT_MAX ? -1 : dp[dst];
}


int dp_is_match(string s, string p, int idx_s, int idx_p){
    // base line
    if ((s == "" && p != "") || (s != "" && p == "")) {
        return -1;
    }

    // 
    int size_i = s.size();
    int size_j = p.size();
    for (int i = idx_s, j = idx_p; i < size_i && j < size_j; i++, j++)
    {
        if(p[j] == '.'){
            // 
        } else if (s[i] != p[j] && p[j+1] != '*') {
            return -1;
        } else if (s[i] != p[j] && p[j+1] == '*') {
            j++; 
        } else if (s[i] == p[j] && p[j+1] != '*'){

        } else if (s[i] == p[j] && p[j+1] == '*'){
            // dp处理
            int tmp = 0;
            int idx = i+1;
            // idx 溢出处理
            while(s[idx] == s[i]) {
                tmp++;
            }
            
            int ret;
            for (int k = 0; k <= tmp; k++)
            {
                ret = dp_is_match(s, p, (i+k), j);
                if (ret == 0) {
                    break;
                }
            }

            if (ret == -1) return -1;
        

        } else {// j+1 溢出时；
            return -1;
        }

    }

    // i或者j仅其中一方字符完成。


    return 0;// 字符匹配成功；
    
}

// 正则表达式匹配
bool isMatch(string s, string p) {
    
    // int ret = dp_is_match(s, p, 0, 0);

    // if (ret == -1) return false;
    int m = s.size();
    int n = p.size();

    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));//dp[i][j]表示s的前i个字符和p的前j个字符是否匹配。i<-m, j<-n;

    dp[0][0] = true;

    for (int i = 1; i < (n+1); i++)
    {
        /* 空字符s与p满足a*b*c*... */
        if(p[i-1]  == '*')
        {
            dp[0][i] = dp[0][i-2];
        }
    }
       for (int i = 1; i < (m+1); i++)
        {
            for (int j = 1; j < (n+1); j++)
            {
                if(s[i-1] == p[j-1] || p[j-1] == '.'){
                    // 1.a : 当前字符相等；
                    // 1.b : p当前字符为'.';
                    dp[i][j]=dp[i-1][j-1];
                } else if(p[j-1] == '*'){
                    // 2 : 当前字符不相等,下一匹配符为'*'
                    // 2.a : p上一匹配符与s当前字符相等或为'.'
                    if(s[i-1] == p[j-2] || p[j-2] == '.') {
                        // 'x*'匹配n次 | 0次；
                        dp[i][j] = dp[i-1][j] | dp[i][j-2];
                    } else {// 2.b : p上一匹配符与s当前字符不相等
                        dp[i][j] = dp[i][j-2];
                    }
                } else {
                    // 3 : 当前字符不等，且下一匹配符不为'*'
                    dp[i][j] = false;
                }

            }
            
        }

    return dp[m][n];
}


// 鸡蛋掉落
int superEggDrop(int k, int n) {
    
}

// 爬楼梯
int climbStairs(int n) {
    vector<int> dp(n+1, 0); // 表示当前楼梯数到达的方式

    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
    
}

// 使用最小花费爬楼梯
int minCostClimbingStairs(vector<int>& cost) {
    int floor = cost.size()-1;
    vector<int> dp(floor+1, 0);// 表示到达该楼层需要的花费
    dp[1] = 0;
    dp[2] = 0;
    
    for (int i = 1; i < floor; i++)
    {
        if(i < 3) {
            dp[i] = 0;
        } else {
            dp[i] = min((dp[i-1] + cost[i-1]), (dp[i-2]+cost[i-2]));
        }
    }
    
    return dp[floor];
}

// 不同路径
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0)); //dp[i][j]表示到达当前位置的路径数。
    for (int i = 0; i < m; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        dp[0][i] = 1;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
        
    }
    
    return dp[m-1][n-1];

}

// 不同路径 II
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0)); //dp[i][j]表示到达当前位置的路径数。
    int tmp_col = -1;
    for (int i = 0; i < m; i++)
    {   
        if(obstacleGrid[i][0] == 1) tmp_col = i;

        if(tmp_col == -1) {
            dp[i][0] = 1;
        } else {
            dp[i][0] = 0;
        }
    }
    
    int tmp_row = -1;
    for (int i = 0; i < n; i++)
    {
        if(obstacleGrid[0][i] == 1) tmp_row = i;

        if(tmp_row == -1) {
            dp[0][i] = 1;
        } else {
            dp[0][i] = 0;
        }
    }

    int tmp1, tmp2;
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if(obstacleGrid[i][j] == 1) continue;

            tmp1 = obstacleGrid[i][j-1] == 1 ? 0 : dp[i][j-1];
            tmp2 = obstacleGrid[i-1][j] == 1 ? 0 : dp[i-1][j];

            dp[i][j] = tmp1 + tmp2;
        }
        
    }


    return dp[m-1][n-1];
}

// 整数拆分
// int dp_integerBreak(vector<int> mem, int k) {
//     int res;
//     int tmp;
//     for (int i = 2; i < k; i++)
//     {
//         if (mem[i] != 0) {
//             tmp = mem[i];
//         } else {
//             tmp = dp_integerBreak(mem, i);
//         }
//         res = max(res, tmp*(k-i));
//     }
    
//     mem[k] = res;

//     return res;
// }

// int integerBreak(int n) {

//     if (n == 2 || n == 3) {
//         return n-1;
//     }

//     vector<int> mem(n+1, 0);
//     mem[2] = 2;
//     mem[3] = 3;

//     return dp_integerBreak(mem, n);
// }



int integerBreak(int n) {
    




}





int main(){

    // bool ret = isPalindrome(123);
    // cout << ret << endl;
    // Solution s;
    vector<int> nums1 = {10,9,2,5,3,7,101,18};
    vector<int> nums2 = {2};
    vector<int> nums3 = {5,2, 1};

    // bool ret = isMatch("aa", "a");

    vector<vector<int>> aa = {{1,0}};
    int res = uniquePathsWithObstacles(aa);

    cout << "run over" << endl;
    return 0;
}

