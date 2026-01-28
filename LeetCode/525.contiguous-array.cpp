/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        int maxi = 0;
        int sum = 0;
        vector<int> ps(n);
        unordered_map<int, int> mp;

        for (int i=0 ; i<n ; i++){
            if (nums[i]==1) sum++;
            else sum--;

            if (sum==0){
                maxi = max(i+1, maxi);
                continue;
            }

            int target = sum;
            if (mp[target]) maxi = max(maxi, i - mp[target]);

            if(mp.count(sum)) continue;
            else mp[sum]=i;
        }

        return maxi;
    }
};
// @lc code=end

