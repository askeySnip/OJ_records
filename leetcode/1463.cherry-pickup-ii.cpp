/*
 * @lc app=leetcode id=1463 lang=cpp
 *
 * [1463] Cherry Pickup II
 */

// @lc code=start
class Solution {
public:
    int dp[75][75][75];
    int r, c;
    int cherryPickup(vector<vector<int>>& grid) {
        r = grid.size(), c = grid[0].size();
        memset(dp, -1, sizeof dp);
        return helper(grid, 0, 0, c-1);
    }
    int helper(vector<vector<int>>& grid, int cur_row, int a, int b) {
        if(cur_row == r) return 0;
        if(a >= b) return 0;
        if(dp[cur_row][a][b] != -1) return dp[cur_row][a][b];
        int& res = dp[cur_row][a][b];
        for(int i=-1; i<=1; i++) {
            if(a+i<0 || a+i >=c) continue;
            for(int j=-1; j<=1; j++) {
                if(b+j<0 || b+j >= c) continue;
                res = max(res, grid[cur_row][a] + grid[cur_row][b] + helper(grid, cur_row+1, a+i, b+j));
            }
        }
        return res;
    }
};
// @lc code=end

