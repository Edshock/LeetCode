#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


bool isPalindrome(int x) {
    string s = to_string(x);
    string s1 = s;
    reverse(s.begin(), s.end());

    if(s != s1) {
        return false;
    }

    return true;
}

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < n; i++)
        {
            nums1[m+i] = nums2[i];
        }
        
        sort(nums1.begin(), nums1.end());
    }
};

int removeElement(vector<int>& nums, int val) {
    int cnt = 0;
    int idx = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        /* code */
        if (idx == (nums.size())) {
            break;
        }


        if (nums[idx] == val) {
            nums.erase(nums.begin() + idx);
            cnt++;
        } else{
            idx++;
        }
    }

    return (size - cnt);
         
}