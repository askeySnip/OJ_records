/*
 * @lc app=leetcode id=1473 lang=cpp
 *
 * [1473] Paint House III
 */
#include <vector>
// @lc code=start
class Solution {
 public:
  const int inf = 0x3f3f3f3f;
  int f[110][110][22] = {};
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n,
              int target) {
    int ans = helper(houses, cost, 0, target, 0);
    return ans >= inf ? -1 : ans;
  }
  int helper(vector<int>& houses, vector<vector<int>>& cost, int i, int target,
             int lc) {
    if (i >= houses.size() || target < 0) {
      return target == 0 ? 0 : inf;
    }
    if (f[i][target][lc]) return f[i][target][lc];
    if (houses[i]) {
      return f[i][target][lc] = helper(houses, cost, i + 1,
                                       target - (lc != houses[i]), houses[i]);
    }
    int& res = f[i][target][lc];
    res = inf;
    for(int j=1; j<=cost[i].size(); j++) {
        res = min(res, cost[i][j-1] + helper(houses, cost, i+1, target - (lc != j), j));
    }
    return res;
  }
};
// @lc code=end
