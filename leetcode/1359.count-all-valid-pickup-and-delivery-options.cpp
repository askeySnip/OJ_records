/*
 * @lc app=leetcode id=1359 lang=cpp
 *
 * [1359] Count All Valid Pickup and Delivery Options
 */

// @lc code=start
class Solution {
 public:
  vector<int> f;
  const int mod = 1e9 + 7;
  int countOrders(int n) {
    f.assign(n + 1, 0);
    f[1] = 1;
    return helper(n);
  }
  int helper(int n) {
    if (n == 1) return 1;
    if (f[n]) return f[n];
    int o = helper(n - 1);
    int c = n * (n * 2 - 1);
    f[n] = 1LL * o * c % mod;
    return f[n];
  }
};
// @lc code=end
