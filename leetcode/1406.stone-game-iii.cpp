/*
 * @lc app=leetcode id=1406 lang=cpp
 *
 * [1406] Stone Game III
 */

// @lc code=start
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> f(n, -1e9);
        for(int i=n-1; i>=0; i--) {
            for(int k=0, take=0; k<3 && k+i<n; k++) {
                take += stoneValue[i+k];
                f[i] = max(f[i], take - (i+k+1 < n ? f[i+k+1] : 0));
            }
        }
        return f[0] == 0 ? "Tie" : (f[0] > 0 ? "Alice" : "Bob");
    }
};
// @lc code=end

