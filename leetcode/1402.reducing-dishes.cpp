/*
 * @lc app=leetcode id=1402 lang=cpp
 *
 * [1402] Reducing Dishes
 */

// @lc code=start
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int ans, n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        int zero = lower_bound(satisfaction.begin(), satisfaction.end(), 0) - satisfaction.begin();
        int cur = 0, s = 0;
        for(int i=0; i+zero<n; i++) {
            cur += satisfaction[i+zero] * (i+1);
            s += satisfaction[i+zero];
        }
        ans = cur;
        for(int i=zero-1; i>=0; i--) {
            if(s < -satisfaction[i]) break;
            s += satisfaction[i];
            cur += s;
        }
        return cur;
    }
};
// @lc code=end

