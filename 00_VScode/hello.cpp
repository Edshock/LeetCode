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

    bool isMatch(string s, string p) {
        
    }

int main(){

    // bool ret = isPalindrome(123);
    // cout << ret << endl;
    // Solution s;
    vector<int> nums1 = {10,9,2,5,3,7,101,18};
    vector<int> nums2 = {2};
    vector<int> nums3 = {5,2, 1};



    cout << "run over" << endl;
    return 0;
}

