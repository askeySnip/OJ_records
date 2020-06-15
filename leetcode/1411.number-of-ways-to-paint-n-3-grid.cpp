/*
 * @lc app=leetcode id=1411 lang=cpp
 *
 * [1411] Number of Ways to Paint N × 3 Grid
 */

// @lc code=start
class Solution {
public:
    const int mod = 1e9 + 7;
    int numOfWays(int n) {
        long long a121 = 6, a123 = 6, b121, b123;
        for(int i=1; i<n; i++) {
            b123 = (a121 + a123)<<1;
            b121 = b123 + a121;
            a121 = b121 % mod;
            a123 = b123 % mod;
        }
        return (a121 + a123) % mod;
    }
    
};
// @lc code=end

