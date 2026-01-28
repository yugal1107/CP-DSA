#include<algorithm>
#include<bits/stdc++.h>
/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution {
public:

    struct VectorHash {
        size_t operator()(const vector<int>& v) const {
            size_t h = 0;
            for (int x : v) {
                // A simple hash combine
                h ^= std::hash<int>()(x) + 0x9e3779b9 + (h << 6) + (h >> 2);
            }
            return h;
        }
    };

    vector<vector<int>> threeSum(vector<int>& nums) {
        
        unordered_set<vector<int>, VectorHash> s;
        int n = nums.size();
        
        for (int i=0 ; i<n ; i++){
            unordered_set<int> mp;
            for (int j=i+1 ; j<n ; j++){
                int target = 0 - nums[i] - nums[j];
                if (mp.find(target)!=mp.end()){
                    vector<int> temp = {nums[i], nums[j], target};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                }
                mp.insert(nums[j]);
            }
        }

        return vector(s.begin(), s.end());
    }
};
// @lc code=end

