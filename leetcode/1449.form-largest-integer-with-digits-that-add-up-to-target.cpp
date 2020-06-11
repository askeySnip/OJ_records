/*
 * @lc app=leetcode id=1449 lang=cpp
 *
 * [1449] Form Largest Integer With Digits That Add up to Target
 */

// @lc code=start
class Solution {
public:
    const int inf = 0x3f3f3f3f;
    string largestNumber(vector<int>& cost, int target) {
        vector<int> dp(target + 1, -inf);
        dp[0] = 0;
        for(int i=1; i<=target; i++) {
            for(int j=0; j<9; j++) {
                dp[i] = max(dp[i], i >= cost[j] ? 1 + dp[i-cost[j]] : -inf);
            }
        }
        if(dp[target] < 0) return "0";
        string ans;
        for(int i=8; i>=0; i--) {
            while(target >= cost[i] && dp[target] == dp[target-cost[i]] + 1) {
                ans += (char)(i+'1');
                target -= cost[i];
            }
        }
        return ans;
    }
};
// @lc code=end

