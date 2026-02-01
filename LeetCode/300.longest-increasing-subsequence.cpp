/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int idx, int prev, vector<int>& nums){
        int n = nums.size();

        // base case 
        if (idx == n) return 0;

        if (dp[idx][prev+1]!=-1) return dp[idx][prev+1];

        int take, nt;

        //take
        if (prev==-1 || nums[idx] > nums[prev]){
            take = solve(idx+1, idx, nums) + 1;
        }

        // not take
        nt = solve(idx+1, prev, nums);

        return dp[idx][prev+1] = max(nt, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n+1, vector<int>(n+1, -1));
        return solve(0, -1, nums);
    }
};
// @lc code=end

