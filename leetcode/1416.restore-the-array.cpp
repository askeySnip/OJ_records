/*
 * @lc app=leetcode id=1416 lang=cpp
 *
 * [1416] Restore The Array
 */

// @lc code=start
class Solution {
 public:
  int numberOfArrays(string s, int k) {
    int n = s.length();
    const int mod = 1e9 + 7;
    vector<int> f(n + 1, 0);
    if (s[0] == '0' || s[0] - '0' > k) return 0;
    f[n] = 1;
    for(int i=n-1; i>=0; i--) {
        if(s[i] == '0') continue;
        long long cur = 0;
        for(int j=i; j<n; j++) {
            cur = cur * 10 + s[j] - '0';
            if(cur > k) break;
            if(cur >= 1 && cur <= k) f[i] += f[j+1], f[i] %= mod;
        }
    }

    return f[0];
  }
};
// @lc code=end
