/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLength = INT_MAX;
        int n = strs.size();

        for (string& str: strs){
            int si = str.size();
            minLength=min(minLength, si);
        }
        
        string prefix;
        for (int i=0 ; i<minLength ; i++){
            char ch = strs[0][i];
            bool find = true;
            for (int j=0 ; j<n ; j++){
                if (strs[j][i]!=ch){
                    find = false;
                    break;
                }
            }

            if (find) prefix+=ch;
            else break;
        }

        return prefix;
    }
};
// @lc code=end

